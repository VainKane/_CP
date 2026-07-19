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

int const N = 109;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;

int a[36];
map<vector<int>, int> dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    REP(i, m) cin >> a[i];

    REP(i, m)
    {
        vector<int> haha;
        REP(j, m)
        {
            if (j == i) haha.push_back(0);
            else haha.push_back(a[j]);
        }

        dp[1][haha] = 1;
    }

    FOR(i, 1, n) for (auto &p : dp[i]) REP(j, m) if (p.F[j] + 1 >= a[j])
    {
        vector<int> v = p.F;
        REP(id, sz(v))
        {
            if (id == j) v[id] = 0;
            else v[id] = min(v[id] + 1, a[id]);
        }

        Add(dp[i + 1][v], p.S);
    }

    int res = 0;
    for (auto &p : dp[n]) Add(res, p.S);
    cout << res;

    return 0;
}