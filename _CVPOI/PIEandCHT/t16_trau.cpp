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

int const N = 1e5 + 5;
int const Q = 3e5 + 5;
long long const oo = 4e18;

int n, q;
int v[N], t[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> t[i] >> v[i], v[i] = abs(v[i]);

    while (q--)
    {
        int ti; cin >> ti;
        long long mi = oo;

        int res = -1;
        FOR(j, 1, n) if (t[j] <= ti && mini(mi, 1LL * (ti - t[j]) * v[j])) res = j;
        cout << res << ' ';
    }

    return 0;
}