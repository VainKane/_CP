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
int const BK = 314;
int const GR = N / BK + 5;
int const oo = 1e9;
int bkId[N], bkL[GR], bkR[GR];

int n, q;
vector<int> adj[N];
pair<int, int> qr[N];

int up[2 * N][20];
int pos[N];
int timer = 0;

int h[N], d[N];

bool cmp(int u, int v)
{
    return pos[u] < pos[v];
}

void DFS(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFS(v, u);
        up[++timer][0] = u;
    }
}

void Build()
{
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

int Dist(int u, int v)
{
    return h[u] + h[v] - 2 * h[LCA(u, v)];
}

void BFS(int l, int r)
{
    if (l > r) return;

    memset(d, 0x3f, sizeof d);
    queue<int> q;
    
    FOR(i, l, r) if (qr[i].F == 1)
    {
        q.push(qr[i].S);
        d[qr[i].S] = 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) if (d[v] > oo)
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void Init()
{
    FOR(i, 1, q)
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
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
    Build();

    memset(d, 0x3f, sizeof d);
    h[0] = -1;

    Init();

    FOR(id, 1, bkId[q])
    {
        BFS(1, bkR[id - 1]);
        vector<int> nodes = {1};

        FOR(i, bkL[id], bkR[id])
        {
            int u = qr[i].S;
            if (qr[i].F == 1) nodes.push_back(u);
            else
            {
                int res = d[u];
                for (auto &v : nodes) mini(res, Dist(u, v));
                cout << res << '\n';
            }
        }
    }

    return 0;
}