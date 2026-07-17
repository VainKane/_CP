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
#define name "nexist"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1009;
int const oo = 1e9;

int n, m;
string s, t;

int f[N][N];

int last[256];
int nxt[N][256];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> s >> t;

    n = sz(s), m = sz(t);
    s = " " + s;
    t = " " + t;

    REP(i, 256) last[i] = m + 1;

    FORD(i, m, 0) 
    {
        REP(j, 256) nxt[i][j] = last[j];
        last[t[i]] = i;        
    }

    int res = oo;

    FOR(i, 1, n) FOR(j, 1, i) 
    {
        FOR(k, 0, i - 1) maxi(f[i][j], nxt[f[k][j - 1]][s[i]]);
        if (f[i][j] > m) mini(res, j);
    }

    if (res == oo) res = -1;
    cout << res;

    return 0;
}