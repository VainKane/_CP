#include <bits/stdc++.h>

using namespace std;

int const M = 15;

int n;
int m;

string a[M + 5];
int c[M + 5][M + 5];
int dp[(1 << M) + 5][M + 5];

int Cost(string a, string b)
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i]) res++;
    }

    return res;
}

int Count(string a)
{
    int res = 0;
    
    for (auto ch : a)
    {
        if (ch == '1') res++;
    }

    return res;
}

int bit(int i, long long x)
{
    return (x >> i) & 1;
}

long long TurnOff(int i, long long x)
{
    return x & (~(1 << i));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof dp);

    for (int i = 0; i < m; i++)
    {
        dp[1 << i][i] = Count(a[i]);

        for (int j = 0; j < m; j++)
        {
            c[i][j] = c[j][i] = Cost(a[i], a[j]);
        }
    }

    for (int x = 0; x < (1 << m); x++)
    {
        for (int i = 0; i < m; i++)
        {
            if (!bit(i, x)) continue;

            for (int j = 0; j < m; j++)
            {
                if (i == j) continue;
                if (!bit(j, x)) continue;

                dp[x][i] = min(dp[x][i], dp[TurnOff(i, x)][j] + c[j][i]);
            }
        }
    }

    int res = 1e9;
    for (int i = 0; i < m; i++) 
    {
        res = min(res, dp[(1 << m) - 1][i]);
    }
    
    cout << res;

    return 0;
}