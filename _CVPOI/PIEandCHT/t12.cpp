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

int const N = 2e5 + 5;
int const MOD = 1e9 + 7;

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

int n, k;
bool visited[N];
int p[N], sz[N];
int cc = 0;

int f[N], inv[N];

void DFS(int u, int nodeId)
{
    visited[u] = true;
    sz[nodeId]++;
    if (!visited[p[u]]) DFS(p[u], nodeId);
}

void Init()
{
    f[0] = 1;
    FOR(i, 1, n) f[i] = 1LL * f[i - 1] * i % MOD;

    inv[n] = PowMod(f[n], MOD - 2);
    FORD(i, n - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
}

int C(int n, int k)
{
    if (n < k) return 0;
    return 1LL * f[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> p[i];

    FOR(u, 1, n) if (!visited[u]) DFS(u, ++cc);
    Init();

    int res = 1;
    FOR(i, 1, cc)
    {
        int tmp = 0;
        REP(cnt, k) tmp = (tmp + ((cnt & 1) ? -1LL : 1LL) * C(k, cnt) * PowMod(k - cnt, sz[i])) % MOD;
        res = 1LL * res * (tmp + MOD) % MOD;
    }

    cout << res;

    return 0;
}