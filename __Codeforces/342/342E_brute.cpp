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

int const N = 1e5 + 5;
int const LOG = 18;
int const BK = 314;
int bkId[N], bkL[N], bkR[N];

int n, q;

vector<int> adj[N];
pair<int, int> qr[N];

int h[N];
int up[2 * N][20];

int in[N];
int timer = 0;

bool visited[N];
int d[N];

void DFS(int u, int p)
{
    up[in[u] = ++timer][0] = u;
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFS(v, u);
        up[++timer][0] = u;
    }
}

bool cmp(int u, int v)
{
    return h[u] < h[v];
}

void Init()
{
    FOR(i, 1, q)
    {
        int &id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }

    FOR(j, 1, LOG) FOR(i, 1, timer - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = in[u], v = in[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

int Dist(int u, int v)
{
    return h[u] + h[v] - 2 * h[LCA(u, v)];
}

void BFS(vector<int> &nodes)
{
    memset(visited, false, sizeof visited);

    queue<int> q;
    for (auto &u : nodes) 
    {
        visited[u] = true;
        d[u] = 0;
        q.push(u);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) if (!visited[v])
        {
            visited[v] = true;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;

    DFS(1, -1);
    Init();

    FOR(id, 1, bkId[q])
    {
        vector<int> nodes = {1};
        FOR(i, 1, bkR[id - 1]) if (qr[i].F == 1) nodes.push_back(qr[i].S);
        BFS(nodes);

        FOR(i, bkL[id], bkR[id])
        {
            if (qr[i].F == 1) FOR(j, i + 1, bkR[id]) mini(d[qr[j].S], Dist(qr[i].S, qr[j].S));
            else cout << d[qr[i].S] << '\n';
        }
    }

    return 0;
}