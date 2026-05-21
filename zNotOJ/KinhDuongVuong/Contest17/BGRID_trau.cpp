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
#define name ""

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5009;

int n, p;
bool a[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    FOR(i, 1, p)
    {
        int t, w;
        cin >> t >> w;

        if (t == 1) FOR(x, 1, w) FOR(y, 1, w) a[x][y] ^= 1;
        else FOR(x, w, n) FOR(y, w, n) a[x][y] ^= 1;
    }

    int q; cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << a[x][y] << '\n';
    }

    return 0;
}
