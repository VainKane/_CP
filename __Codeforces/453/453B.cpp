#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

int const N = 109;
int oo = 1e9;

int n;

vector<int> primes;

int a[N];
int dp[N][MK(17) + 5];

int divMask[N];
vector<int> g[MK(17) + 5];

int trace[N][MK(17) + 5];

bool Prime(int x)
{
    FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
    return x > 1; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 2, 60) if (Prime(i)) primes.push_back(i);

    FOR(x, 1, 60) 
    {
        REP(i, sz(primes)) if (x % primes[i] == 0) divMask[x] |= MK(i);

        int invMask = divMask[x] ^ (MK(17) - 1);
        for (int tmp = invMask; tmp; tmp = (tmp - 1) & invMask)
        {
            g[tmp | divMask[x]].push_back(x);
        }
    }

    FOR(i, 1, n) REP(mask, MK(17)) 
    {
        dp[i][mask] = oo;
        for (auto &x : g[mask])
        {
            if (mini(dp[i][mask], dp[i - 1][mask ^ divMask[x]] + abs(a[i] - x)))
            {
                trace[i][mask] = x;
            }
        }
    }

    int sum = oo;
    int curMask = 0;

    REP(mask, MK(17)) if (mini(sum, dp[n][mask])) curMask = mask;

    vector<int> res;
    FORD(i, n, 1)
    {
        res.push_back(trace[i][curMask]);
        curMask = curMask ^ divMask[trace[i][curMask]];
    }

    reverse(all(res));
    for (auto &x : res) cout << x << ' ';

    return 0;
}