#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2009;

int n, A, C;

int a[N], b[N], c[N];
int dp[2][N][N];

int cur = 0, pre = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> A >> C;
    FOR(i, 1, n) cin >> a[i] >> b[i] >> c[i];
    
    FOR(i, 1, n) 
    {
        swap(cur, pre);

        FOR(x, 0, A) FOR(y, 0, C)
        {
            dp[cur][x][y] = dp[pre][x][y];
            FORD(k, min(x, b[i]), 0) 
            {
                if (y < c[i] * (b[i] - k)) break;
                maxi(dp[cur][x][y], dp[pre][x - k][y - c[i] * (b[i] - k)] + a[i]);
            }
        }
    }

    int res = 0;
    FOR(i, 0, A) FOR(j, 0, C) maxi(res, dp[cur][i][j]);

    cout << res;

    return 0;
}