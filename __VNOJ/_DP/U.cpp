#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1 << (i))

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 16;

int n;
int a[N][N];

long long cost[MK(N)];
long long dp[MK(N)];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) REP(j, n) cin >> a[i][j];

    REP(mask, MK(n)) 
    {
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            for (int haha = tmp; haha; haha ^= haha & -haha)
            {
                int j = __builtin_ctz(haha);
                cost[mask] += a[i][j];
            }
        }
    }

    REP(mask, MK(n))
    {
        for (int tmp = mask; tmp; tmp = (tmp - 1) & mask)   
            maxi(dp[mask], dp[mask ^ tmp] + cost[tmp]);
    }

    cout << dp[MK(n) - 1];

    return 0;
}