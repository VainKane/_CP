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
#define name "METRO"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n;
int c[N];
int l[N], r[N];

int g[N], f[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n) 
    {
        cin >> l[i] >> r[i];
        
        l[i] += i;
        r[i] += i;
    }

    g[1] = 1;

    FOR(i, 2, n) 
    {
        FOR(j, 1, i - 1) if (l[j] <= i && r[j] >= i) 
        {
            Add(g[i], g[j]);
            Add(f[i], (f[j] + 1ll * g[j] * c[j]) % MOD);
        }
    }

    // FOR(i, 1, n) cout << g[i] << ' ';
    cout << f[n];

    return 0;
}