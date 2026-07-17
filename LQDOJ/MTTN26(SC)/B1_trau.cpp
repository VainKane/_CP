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

int const N = 36;

int n, t, s;
int a[N], p[N];

long long sumMask[MK(20) + 5];
long long dp[MK(20) + 5];
int trace[MK(20) + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t >> s;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> p[i];

    REP(mask, MK(n))
    {
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            sumMask[mask] += a[i];
        }
    }

    REP(mask, MK(n)) for (int tmp = mask ^ (MK(n) - 1); tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        if (sumMask[mask | MK(i)] > t) continue;
        if (maxi(dp[mask | MK(i)], max(0LL, dp[mask] + 1LL * p[i] * s - 1LL * sumMask[mask | MK(i)] * p[i])))
            trace[mask | MK(i)] = i;
    }

    int hihi = 0;
    long long res = 0;

    REP(mask, MK(n)) if (maxi(res, dp[mask])) hihi = mask;
    
    cout << __builtin_popcount(hihi) << ' ' << res << '\n';

    vector<int> path;
    while (hihi)
    {
        path.push_back(trace[hihi] + 1);
        hihi ^= MK(trace[hihi]);
    }
    
    reverse(all(path));
    for (auto &id : path) cout << id << ' ';

    return 0;
}