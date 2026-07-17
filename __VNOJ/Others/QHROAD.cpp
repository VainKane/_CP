#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define F first
#define S second

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n, res;

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
        res = n = _n;
        par.resize(n + 3);
        sz.resize(n + 3);
    
        if (n) MakeSet();
    }

    int Find(int v)
    {
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        
        sz[a] += sz[b];
        par[b] = a;
        res--;
    }
};

int const N = 1e5 + 5;

int n, m, q;
pair<int, int> edges[N];

int qr[N], res[N];
bool mark[N];

DSU dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    FOR(i, 1, q) 
    {
        cin >> qr[i];
        mark[qr[i]] = true;
    }
    
    dsu = DSU(n);
    FOR(i, 1, m) if (!mark[i]) dsu.Union(edges[i].F, edges[i].S);

    FORD(i, q, 1)
    {
        res[i] = dsu.res;
        dsu.Union(edges[qr[i]].F, edges[qr[i]].S);
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}