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

int const N = 3009;
int const oo = 1e8 + 1;

int n;
int s[N], c[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, n) cin >> c[i];

    int res = 1e9;

    FOR(i, 1, n)
    {
        int tmp = c[i], mi = oo;

        FOR(j, 1, i - 1) if (s[j] < s[i]) mini(mi, c[j]);
        if (mi == oo) continue;

        tmp += mi;

        mi = oo;
        FOR(j, i + 1, n) if (s[j] > s[i]) mini(mi, c[j]);
        if (mi == oo) continue;

        mini(res, tmp + mi);
    }

    cout << (res == 1e9 ? -1 : res);

    return 0;
}