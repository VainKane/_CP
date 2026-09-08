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
#define name "BOARDGAME"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5009;

int n, d;
int p[N], t[N], o[N];
long long dp[N];

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 10;
    }

    void Process()
    {
        long long res = 0;
        REP(mask, MK(n))
        {
            int s = d;
            for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp);
                s -= p[i + 1];
            }

            memset(dp, 0, sizeof dp);
            FOR(i, 1, n) FOR(j, t[i], s) if (BIT(i - 1, mask))
                maxi(dp[j], dp[j - t[i]] + o[i]);

            if (s > 0) maxi(res, dp[s]);
        }

        cout << res;
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        FOR(i, 1, n) if (p[i]) return false;
        return true;
    }

    void Process()
    {
        FOR(i, 1, n) FOR(j, t[i], d) maxi(dp[j], dp[j - t[i]] + o[i]);
        cout << dp[d];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> d;
    FOR(i, 1, n) cin >> p[i] >> t[i] >> o[i];

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub2::CheckSub()) return Sub2::Process(), 0;

    return 0;
}