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

int const N = 1009;
int const MOD = 1e6 + 3;

void Add(int &x, int const &y, int delta)
{
    x += delta * y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return res;
}

int m, n;
vector<pair<int, int>> pos;

bool markC[N], markR[N];
int f[N], inv[N];

int g[N];

int Cal(int mask)
{
    bool ok = true;

    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        if (markR[pos[i].F] || markC[pos[i].S]) ok = false;
        markR[pos[i].F] = markC[pos[i].S] = true;
    }
    
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        markR[pos[i].F] = markC[pos[i].S] = false;
    }

    return ok ? g[__builtin_popcount(mask)] : 0;
}

void Init()
{
    f[0] = 1;
    FOR(i, 1, max(m, n)) f[i] = f[i - 1] * i % MOD;
    
    inv[max(m, n)] = PowMod(f[max(m, n)], MOD - 2);
    FORD(i, max(m, n) - 1, 0) inv[i] = inv[i + 1] * (i + 1) % MOD;

    FOR(d, 0, min(m, n)) FOR(i, 0, min(m, n) - d)
    {
        int tmp = 1LL * f[m - d] * f[n - d] * inv[m - d - i] % MOD;
        tmp = 1LL * tmp * inv[n - d - i] * inv[i] % MOD;
        Add(g[d], tmp, 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        char ch; cin >> ch;
        if (ch == '#') pos.push_back({i, j});
    }

    Init();

    int res = 0;
    REP(mask, MK(sz(pos))) Add(res, Cal(mask), __builtin_parity(mask) ? -1 : 1);
    cout << res;

    return 0;
}