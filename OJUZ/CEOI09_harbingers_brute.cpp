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
#define name "harbingers"

using ll = long long;
using ii = pair<int, int>;

template <class t> bool maxi(t &x, t const &y) { return x < y ? x = y, 1 : 0; }
template <class t> bool mini(t &x, t const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
ll const oo = 1e18;

int n;
vector<pair<int, int>> adj[N];
int s[N], t[N], d[N];

int par[N];
ll dp[N];

void DFS(int u, int p)
{
    for (auto &e : adj[u]) 
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;
        
        d[v] = d[u] + w;
        par[v] = u;

        int node = v;
        dp[v] = oo;

        while (node)
        {
            node = par[node];
            mini(dp[v], dp[node] + 1LL * t[v] * (d[v] - d[node]) + s[v]);
        }
        
        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".in", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 2, n) cin >> s[i] >> t[i];

    DFS(1, -1);
    FOR(u, 2, n) cout << dp[u] << ' ';

    return 0;
}