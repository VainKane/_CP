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
#define name "XOREX"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = MK(19) + 5;

int n, q;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> q;
    REP(i, n) cin >> a[i];

    while (q--)
    {
        int type, x, l, r;
        cin >> type;
        
        if (type == 1)
        {
            cin >> x;
            REP(i, n) if (i < (i ^ x)) swap(a[i], a[i ^ x]);
        }
        else if (type == 2)
        {
            cin >> l >> r;
            
            long long res = 0;
            FOR(i, l, r) res += a[i];
            cout << res << '\n';
        }
        else
        {
            cin >> l >> r;

            long long res = 0;
            FOR(i, l, r) res += 1ll * a[i] * (i - l + 1);
            cout << res << '\n';
        }
    }

    return 0;
}