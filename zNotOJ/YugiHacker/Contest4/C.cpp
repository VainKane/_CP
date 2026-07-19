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
#define name "manage"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e3 + 5;
int const oo = 1e9;

int n, m, q;

int a[N];
vector<int> adj[N];

bitset<N> go[N];

vector<int> topo;
int inDeg[N];

int pos[N];

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (!inDeg[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto &v : adj[u]) if (!--inDeg[v]) q.push(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q;
    
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }

    BFS();
    for (auto &u : topo) for (auto &v : adj[u])
    {
        go[v][u] = true;
        go[v] |= go[u];
    }

    FOR(u, 1, n) pos[u] = u;

    while (q--)
    {
        int type, u, v;
        cin >> type;
        
        if (type == 1)
        {
            cin >> u >> v;
            swap(pos[u], pos[v]);
            swap(a[pos[u]], a[pos[v]]);
        }
        else
        {
            cin >> v;
            v = pos[v];

            int res = oo;
            FOR(u, 1, n) if (u != v && go[v][u]) mini(res, a[u]);
            if (res == oo) res = 0;

            cout << res << '\n';
        }
    }

    return 0;
}