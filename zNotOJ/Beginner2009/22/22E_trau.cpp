#include <bits/stdc++.h>

using namespace std;

int const N = 20;

int n;
bool used[N + 5];

int a[N + 5];
int b[N + 5];
int x[N + 5];

bool cb[N + 5][N + 5];
bool cx[N + 5][N + 5];

int res = 0;

bool Check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int u = a[i];
            int v = a[j];

            if (cb[u][v])
            {
                if (!cx[u][v]) return false;
            }
        }
    }

    return true;
}

void Try(int pos)
{
    if (pos > n)
    {
        memset(cx, 0, sizeof cx);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                cx[a[x[i]]][a[x[j]]] = true;
            }
        }
        res += Check();

        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            x[pos] = i;

            Try(pos + 1);
            used[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("22E.inp", "r", stdin);
    freopen("22E.ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cb[b[i]][b[j]] = true;
        }
    }
    
    Try(1);

    cout << res;

    return 0;
}