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
#define name "MAXVAL"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;
int const oo = 1e9;

int n, m, k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> a[i];

    long long res = 0;
    FOR(l, 1, n - k + 1) FOR(r, l + k - 1, n)
    {
        vector<int> v;
        FOR(i, l, r) v.push_back(a[i]);
        sort(all(v));

        int tmp = oo;
        REP(i, sz(v) - 1) mini(tmp, v[i + 1] - v[i]);
        maxi(res, 1LL * (r - l + 1) * tmp);
    }

    cout << res;

    return 0;
}