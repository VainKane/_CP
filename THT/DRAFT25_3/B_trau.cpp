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
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define TASKNAME "TASKNAMEGOESHERE"

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

template<typename T> bool mini(T &a, const T &b) {
     return a > b ? a = b, 1 : 0;
}

template<typename T> bool maxi(T &a, const T &b) {
     return a < b ? a = b, 1 : 0;
}

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n, q;
int a, b, x;
int A[maxn];
vi2d g;

namespace sub1 {
    const int maxn = 1005;

    bool check() { return n < maxn; }

    int par[maxn], depth[maxn];
    int x;

    void dfs(int u) {
        for (const int &v: g[u]) if (v != par[u]) par[v] = u, depth[v] = depth[u] + 1, dfs(v);
    }

    int gcd(int _a, int _b) { return _b == 0 ? a : gcd(_b, _a % _b); }

    int GCD(int a, int b)
    {
        while (true)
        {
            if (a == 0 || b == 0 || a == b) return a | b;
            if (a > b) a %= b; else b %= a;
        }
    }

    int GetGCD(int u, int v)
    {
        if (depth[u] < depth[v]) swap(u, v);
        int res = 1;

        while (depth[u] > depth[v])
        {
            res = 1LL * res * GCD(A[u], x) % MOD;
            u = par[u];
        }

        if (u == v) return 1LL * res * GCD(A[u], x) % MOD;

        while (u != v)
        {
            res = 1LL * res * GCD(A[u], x) % MOD;
            res = 1LL * res * GCD(A[v], x) % MOD;
            u = par[u], v = par[v];
        }

        return 1LL * res * GCD(A[u], x) % MOD;
    }

    void solve() {
        dfs(1);

        while (q--) {
            cin >> a >> b >> x;
            cout << GetGCD(a, b) << '\n';
        }
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        return true;
    }

    int const LOG = 24;

    int d[N][26];
    int up[2 * N][20];

    int pos[N];
    int timer = 0;

    int GCD(int a, int b)
    {
        while (true)
        {
            if (a == 0 || b == 0 || a == b) return a | b;
            if (a > b) a %= b; else b %= a;
        }
    }

    void DFS(int u, int p)
    {
        up[++timer][0] = u;
        pos[u] = timer;

        for (auto &v : g[u]) if (v != p)
        {
            REP(i, LOG) d[v][i] = 1LL * d[u][i] * GCD(A[v], MK(i)) % MOD;
            DFS(v, u);
            up[++timer][0] = u;
        }
    }

    bool cmp(int u, int v)
    {
        return pos[u] < pos[v];
    }

    void Build()
    {
        FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
            up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
    }

    int LCA(int u, int v)
    {
        u = pos[u], v = pos[v];
        if (u > v) swap(u, v);

        int k = 31 - __builtin_clz(v - u + 1);
        return min(up[u][k], up[v - MK(k) + 1][k], cmp);
    }

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

    void Process()
    {
        REP(i, LOG) d[1][i] = GCD(A[1], MK(i));
        DFS(1, -1);
        Build();

        while (q--)
        {
            int u, v, x;
            cin >> u >> v >> x;

            int p = LCA(u, v);
            int i = __builtin_ctz(x & -x);

            int res = 1LL * d[u][i] * d[v][i] % MOD;
            res = 1LL * res * PowMod(d[p][i], MOD - 2) % MOD;

            cout << res << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    g.resize(n + 1);

    FOR(i, 1, n) cin >> A[i];
    for (int i = 1, u, v; i < n; ++i) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    if (sub1::check()) return sub1::solve(), 0;
//    if (Sub2::CheckSub()) return Sub2::Process(), 0;

    return 0;
}
