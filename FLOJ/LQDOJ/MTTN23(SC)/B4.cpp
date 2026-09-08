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
long long const oo = 1e18;

int n, m, q;

int st[N], t[N], s[N];
vector<pair<int, int>> adj[N];

int id[N];
long long f[N];

void DFS(int u, int p)
{
    f[u] = id[u] ? 1LL * t[id[u]] * s[1] : oo;
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;
        DFS(v, u);
        mini(f[u], f[v] + w);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    t[0] = 1e9 + 67;
    FOR(i, 1, m)
    {
        cin >> st[i] >> t[i] >> t[i] >> s[i];
        if (t[id[st[i]]] > t[i]) id[st[i]] = i;
    }

    DFS(1, -1);

    while (q--)
    {
        int u; cin >> u;
        if (f[u] == oo) cout << "-1\n";        
        else cout << fixed << setprecision(6) << (double)f[u] / s[1] << '\n';
    }

    return 0;
}