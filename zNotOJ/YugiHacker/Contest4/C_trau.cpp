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

bool visited[N];
int pos[N];
int f[N];

void DFS(int u)
{
    visited[u] = true;
    f[u] = oo;
    
    for (auto &v : adj[u])
    {
        if (true) DFS(v);
        mini(f[u], min(f[v], a[v]));
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
        adj[v].push_back(u);
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

            memset(visited, false, sizeof(typeid(visited)));

            DFS(v);
            cout << (f[v] < oo ? f[v] : 0) << '\n';
        }
    }

    return 0;
}