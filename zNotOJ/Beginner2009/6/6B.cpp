#include <bits/stdc++.h>

using namespace std;

int m;
int n;

bool a[20][20];
int x[20];

int res = 0;
int p[20];

bool used[20];

void Sum()
{
    int cnt = 0;

    bool g[20];
    memset(g, 0, sizeof g);

    for (int i = 1; i <= n; i++)
    {
        if (a[i][x[i]])
        {
            cnt++;
            g[x[i]] = true;
        }
    }

    if (cnt >= res)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][x[i]])
            {
                p[i] = x[i];
            }       
            else
            {
                for (int j = 1; j <= m; j++)
                {
                    if (!g[x[j]])
                    {
                        p[i] = x[j];
                        g[x[j]] = true;
                        break;
                    }
                } 

            }    
        }
        
        res = cnt;
    }
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
        {
            used[j] = true;
            x[i] = j;

            if (i == n)
            {
                Sum();
            }
            else
            {
                Try(i + 1);
            }

            used[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    Try(1);

    cout << res << '\n';
    for (int i = 1; i <= m; i++) cout << p[i] << ' ';
    
    return 0;
}