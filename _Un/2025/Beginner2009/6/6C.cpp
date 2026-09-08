#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int c[20][20];

int res = INT_MAX;
int k;

int x[20];
int cnt[20];
int sum = 0;

int o = 0;

void Try(int pos)
{
    o++;
    if (pos > m)
    {
        int sum = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = i + 1; j <= m; j++)
            {
                if (x[i] != x[j])
                { 
                    sum += c[i][j];
                }
            }
        }

        res = min(res, sum);
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] < k)
        {
            cnt[i]++;
            x[pos] = i;
            Try(pos + 1);
            cnt[i]--;
        }

        if (cnt[i] == 0)
        {
            break;
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
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }

    k = m / n;

    Try(1);

    cout << res << '\n';
    // cout << o;

    return 0;
}