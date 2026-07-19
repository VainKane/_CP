#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n, k;
long long c;
long long v[N];

namespace Sub1
{
    bool CheckSub()
    {
        return k == 1;
    }

    void Process()
    {
        long long res = 2 * n * c;
        FOR(i, 1, n) res += v[i] * (2 * n - i);
        cout << res;
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        return n <= 300;
    }

    int const N = 309;

    long long pre[N], preI[N];
    long long dp[N][N];

    long long Cost(int l, int r)
    {
        return 2 * r * (c + pre[r] - pre[l - 1]) - (preI[r] - preI[l - 1]);
    }

    void Process()
    {
        FOR(i, 1, n)
        {
            pre[i] = pre[i - 1] + v[i];
            preI[i] = preI[i - 1] + i * v[i];
        }

        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;

        FOR(j, 1, k) FOR(i, 1, n) REP(p, i)
            mini(dp[i][j], dp[p][j - 1] + Cost(p + 1, i));

        cout << *min_element(dp[n] + 1, dp[n] + k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> c;
    FOR(i, 1, n) cin >> v[i];

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}