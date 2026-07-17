#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "difference"

struct Edge
{
    int d, u, v;

    bool operator < (Edge const other) const
    {
        return d < other.d;
    }
};

struct Data
{
    int k, d, pos;

    bool operator < (Data const other) const
    {
        if (k != other.k) return k < other.k;
        if (d != other.d) return d > other.d;
        return pos > other.pos;
    }
};

struct DSU
{
    vector<int> par;
    vector<int> sz;
    vector<int> minVal;

    int n = 0;

    void MakeSet(vector<int> &nodes)
    {
        FOR(i, 1, n)
        {
            minVal[i] = nodes[i - 1];
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(vector<int> &nodes)
    {
        n = nodes.size();

        par.resize(n + 3);
        sz.resize(n + 3);
        minVal.resize(n + 3);
        MakeSet(nodes);
    }

    int Find(int v)
    {
        if (v == par[v]) return v;
        return par[v] = Find(par[v]);
    }  

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        
        par[b] = a;
        sz[a] += sz[b];
        minVal[a] = min(minVal[a], minVal[b]);
    }
};

int const N = 1e6 + 5;

int n, m;

int a[N];
int id[N];
vector<Edge> edges;

Data res = {1, 0, 1};

int GetId(int i, int j)
{
    return (i - 1) * n + j;
}

pair<int, int> GetId(int i)
{
    return {(i - 1) / n + 1, (i - 1) % n + 1};
}

void Init()
{
    FOR(i, 1, m) FOR(j, 1, n)
    {
        int u = GetId(i, j);
        if (j != n)
        {
            int v = GetId(i, j + 1);
            edges.push_back({abs(a[u] - a[v]), u, v});   
        }
        if (i != m)
        {
            int v = GetId(i + 1, j);
            edges.push_back({abs(a[u] - a[v]), u, v});
        }
    }

    sort(all(edges));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    cin >> m >> n;
    FOR(i, 1, m * n) cin >> a[i];

    Init();

    REP(i, edges.size())
    {
        int d = edges[i].d;
        int j = i - 1;

        vector<int> nodes;

        while (j + 1 < edges.size() && edges[j + 1].d == d)
        {
            j++;
            int u = edges[j].u;
            int v = edges[j].v;
            
            if (!id[u])
            {
                nodes.push_back(u);
                id[u] = nodes.size();
            }
            if (!id[v])
            {
                nodes.push_back(v);
                id[v] = nodes.size();
            }
        } 

        DSU dsu(nodes);

        FOR(k, i, j) dsu.Union(id[edges[k].u], id[edges[k].v]);
        FOR(idx, 1, nodes.size())
        {
            int u = dsu.Find(idx);
            res = max(res, {dsu.sz[u], d, dsu.minVal[u]});
        }

        for (auto u : nodes) id[u] = 0;
        i = j;
    }

    pair<int, int> p = GetId(res.pos);
    cout << res.k << ' ' << res.d << ' ' << p.F << ' ' << p.S;

    return 0;
}