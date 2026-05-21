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
int const LOG = 20;
int const oo = 1e9;
int const BK = 1000;
int const GR = N / BK + 5;
int bkId[N], bkL[N], bkR[N];

int n;

vector<int> adj[N];
int qr[N], id[N];

int up[2 * N][LOG];
int pos[N];
int timer = 0;

bool visited[N];
int h[N], d[N];

int f[N], g[N];
int res;

bool cmp(int u, int v)
{
    return pos[u] < pos[v];
}

void DFSPrepare(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFSPrepare(v, u);
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

void Init()
{
    FOR(i, 1, n)
    {
        int &id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }
}

void DFS(int u, int p, int rb)
{
    f[u] = id[u] <= rb ? 0 : oo;
    g[u] = oo;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u, rb);
        if (f[v] + 1 < f[u]) g[u] = f[u], f[u] = f[v] + 1;
        else mini(g[u], f[v] + 1);
    }

    mini(res, f[u] + g[u]);
}

void BFS(int rb)
{
    memset(d, 0x3f, (n + 1) * sizeof(int));
    memset(visited, false, (n + 1) * sizeof(bool));

    queue<int> q;

    FOR(i, 1, rb)
    {
        int u = qr[i];
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

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> qr[i], id[qr[i]] = i;

        FOR(u, 1, n) adj[u].clear();
        timer = 0;
        res = oo;

        FOR(i, 2, n)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFSPrepare(1, -1);
        Build();
        Init();

        FOR(id, 1, bkId[n])
        {
            DFS(1, -1, bkR[id - 1]);
            BFS(bkR[id - 1]);

            FOR(i, bkL[id], bkR[id])
            {
                mini(res, d[qr[i]]);
                FOR(j, bkL[id], i - 1) mini(res, Dist(qr[j], qr[i]));
                if (i > 1) cout << res << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}