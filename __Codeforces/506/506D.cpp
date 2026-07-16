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

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n;

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
        MakeSet();
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
        par[b] = a;
        sz[a] += sz[b];
    }
};

int const N = 2e5 + 5;
int const BK = 314;
int const GR = N / BK + 5;

int n, m;
vector<pair<int, int>> edges[N];

int hvId[N];
int hv = 0;

DSU dsu[GR];

vector<int> adj[N];
unordered_map<int, int> cnt[N];

bool visited[N];
vector<int> ccV[N];
int cc = 0;

void BFS(int s)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        ccV[cc].push_back(u);

        for (auto &v : adj[u]) if (!visited[v])
        {
            visited[v] = true;
            q.push(v);
        }
    }
}

void Init()
{
    FOR(i, 1, m) 
    {
        if (sz(edges[i]) > BK) 
        {
            hvId[i] = ++hv;
            dsu[hv] = DSU(n);
            for (auto &e : edges[i]) dsu[hv].Union(e.F, e.S);
        }
        else
        {
            for (auto &e : edges[i])
            {
                adj[e.F].push_back(e.S);
                adj[e.S].push_back(e.F);
            }

            for (auto &e : edges[i])
            {
                if (!visited[e.F]) cc++, BFS(e.F);
                if (!visited[e.S]) cc++, BFS(e.S);
            }

            FOR(id, 1, cc) for (auto &u : ccV[id]) for (auto &v : ccV[id]) cnt[u][v]++;

            for (auto &e : edges[i])
            {
                visited[e.F] = visited[e.S] = false;
                adj[e.F].clear();
                adj[e.S].clear();
            }

            FOR(i, 1, cc) ccV[i].clear();
            cc = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges[c].push_back({u, v});
    }

    Init();

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int res = cnt[u][v];
        FOR(i, 1, hv) res += dsu[i].Find(u) == dsu[i].Find(v);
        cout << res << '\n';
    }

    return 0;
}