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

struct Edge
{
    int u, v, w;

    int GetOther(int node)
    {
        return u ^ v ^ node;
    }
};

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;
int const oo = 1e9 + 2;

int n, m, q;

vector<Edge> edges = {{0, 0, 0}};
vector<int> adj[N];

int haha = 0;

int in[N], low[N];
int timer = 0, cc = 0;

stack<int> st;
int ccId[N];

int deg[N];

void Tarjan(int u, int p, int x)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &id : adj[u])
    {
        int v = edges[id].GetOther(u);
        int w = edges[id].w;

        if (w < x || v == p || ccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u, x);
            mini(low[u], low[v]);
        }
    }

    if (low[u] >= in[u])
    {
        int v = 0;
        cc++;

        while (v != u)
        {
            v = st.top(); st.pop();
            ccId[v] = cc;
        }
    }
}

bool Check(int x)
{
    Tarjan(1, -1, x);
    for (auto &e : edges) if (e.w >= x)
    {
        int u = ccId[e.u];
        int v = ccId[e.v];

        if (u == v) continue;
        deg[u]++, deg[v]++;
    }

    bool ok = true;
    FOR(id, 1, cc) if (deg[id] == 1) ok = false;

    FOR(u, 1, n) deg[u] = in[u] = low[u] = ccId[u] = 0;
    timer = cc = 0;
    st = stack<int>();

    return ok;
}

int Solve()
{
    int l = -1;
    int r = 1e9;
    int res = l;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

void MakeEdge(int u, int v, int w)
{
    edges.push_back({u, v, w});
    adj[u].push_back(++haha);
    adj[v].push_back(haha);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        MakeEdge(u, v, oo);
    }

    cin >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        MakeEdge(u, v, w);
    }

    cout << Solve() << '\n';

    cin >> q;
    while (q--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        MakeEdge(u, v, w);
        cout << Solve() << '\n';
    }

    return 0;
}