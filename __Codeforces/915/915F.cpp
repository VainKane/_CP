#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

struct DSU
{
    vector<int> par;
    vector<int> sz;
    vector<int> sum;
    int n;

    long long res = 0;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
        sum.assign(n + 5, 0);

        MakeSet();
    }

    int Find(int v)
    {
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b, int val)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        res += sz[a] * (1ll * val * sz[b] - sum[b]);
        if (sz[a] < sz[b]) swap(a, b);

        sz[a] += sz[b];
        sum[a] += sum[b];
        par[b] = a;
    }
};

int const N = 1e6 + 5;

int n;
int a[N];

vector<int> node[N];
vector<int> adj[N];

DSU dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        node[a[i]].push_back(i);
    }

    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(u, 1, n) sort(all(adj[u]), greater<int> ());

    dsu = DSU(n);
    FOR(u, 1, n) dsu.sum[u] = a[u];

    FOR(i, 1, 1e6) for (auto &u : node[i]) for (auto &v : adj[u]) if (a[v] <= a[u]) dsu.Union(u, v, i);
    cout << dsu.res;

    // FOR(i, 1, 9) 
    // {
    //     cout << "node " << i << ": ";
    //     for (auto &u : node[i]) cout << u << ' ';
    //     cout << '\n';
    // }

    return 0;
}