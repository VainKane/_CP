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
#define name "unique"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n;
int a[N];

int last[N];
int nxt[N], pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;

    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n)
    {
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }

    FOR(i, 1, n) last[i] = n + 1;

    FORD(i, n, 1)
    {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    int res = 0;
    FOR(i, 1, n) FOR(j, i + 1, nxt[i] - 1) res += pre[j] <= i;
    cout << res;

    return 0;
}