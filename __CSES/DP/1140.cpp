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

int const N = 2e5 + 5;

int n, m;

int l[N], r[N], w[N];
vector<int> id[2 * N];
long long dp[2 * N];

void Compress()
{
    vector<int> vals;
    
    FOR(i, 1, n) 
    {
        vals.push_back(l[i]);
        vals.push_back(r[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    #define GetId(x) (lower_bound(all(vals), (x)) - vals.begin() + 1)

    FOR(i, 1, n)
    {
        l[i] = GetId(l[i]);
        r[i] = GetId(r[i]);
    }

    m = sz(vals);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> l[i] >> r[i] >> w[i];

    Compress();
    FOR(i, 1, n) id[r[i]].push_back(i);

    FOR(r, 1, m) 
    {
        dp[r] = dp[r - 1];
        for (auto &i : id[r]) maxi(dp[r], dp[l[i] - 1] + w[i]);
    }

    cout << dp[m];

    return 0;
}