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

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
ll const oo = 1e18 + 9;

int n;

vector<int> adj[N];
int a[N];

ll dp[N], f[N];

ll g[N], fPar[N];
ll sum[N], dpPar[N];

ll dpp[N];

void DFSPrepare(int u, int p)
{
    dp[u] = a[u];

    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);

        if (max(dp[v], f[v]) > f[u]) g[u] = f[u], f[u] = max(dp[v], f[v]);
        else maxi(g[u], max(dp[v], f[v]));
        sum[u] += dp[v];
    }

    dp[u] = max(0LL, a[u] - sum[u]) + sum[u];
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        dpPar[v] = sum[u] - dp[v] + dpPar[u];
        fPar[v] = max(fPar[u], dpPar[v]);
        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    ll res = oo;
    FOR(u, 1, n) mini(res, max({max(f[u], fPar[u]), 1LL * a[u], (dpp[u] + 1) / 2}));
    // cout << res;

    // FOR(u, 1, n) cout << max(f[u], fPar[u]) << ' ';
    // cout << dpp[2];
    FOR(u, 1, n) cout << dpp[u] << ' ';

    return 0;
}