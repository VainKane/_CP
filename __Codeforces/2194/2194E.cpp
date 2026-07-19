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

long long const oo = 1e18;

int m, n;
vector<vector<int>> a;
vector<vector<long long>> f, g, pre, suf;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;

        a.assign(m + 5, vector<int> (n + 5, 0));
        f.assign(m + 5, vector<long long> (n + 5, -oo));
        g.assign(m + 5, vector<long long> (n + 5, -oo));
        pre.assign(m + 5, vector<long long> (n + 5, -oo));
        suf.assign(m + 5, vector<long long> (n + 5, -oo));

        FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

        f[1][1] = a[1][1];
        g[m][n] = a[m][n];

        FOR(i, 1, m) FOR(j, 1, n) 
        {
            maxi(f[i + 1][j], f[i][j] + a[i + 1][j]);
            maxi(f[i][j + 1], f[i][j] + a[i][j + 1]);
        }

        FORD(i, m, 1) FORD(j, n, 1)
        {
            maxi(g[i - 1][j], g[i][j] + a[i - 1][j]);
            maxi(g[i][j - 1], g[i][j] + a[i][j - 1]);
        }

        FOR(j, 1, n)
        {
            FOR(i, 1, m) pre[i][j] = max(pre[i - 1][j], f[i][j] + g[i][j] - a[i][j]);
            FORD(i, m, 1) suf[i][j] = max(suf[i + 1][j], f[i][j] + g[i][j] - a[i][j]);
        }

        long long res = oo;
        FOR(i, 1, m) FOR(j, 1, n)
        {
            mini(res, max({pre[i - 1][j + 1], suf[i + 1][j - 1], f[i][j] + g[i][j] - 3LL * a[i][j]}));
        }

        cout << res << '\n';
    }

    return 0;
}