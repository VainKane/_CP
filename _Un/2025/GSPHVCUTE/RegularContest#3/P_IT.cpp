#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "business"

struct SegmentTree
{
    vector<int> t, lz;
    int n;

    SegmentTree (int _n = 0)
    {
        n = _n;
        t.resize(4 * n);
        lz.resize(4 * n);
    }

    void Push(int v)
    {
        if (lz[v])
        {
            t[2 * v] += lz[v];
            t[2 * v + 1] += lz[v];
            lz[2 * v] += lz[v];
            lz[2 * v + 1] += lz[v];

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left || l > r || left > right) return;
        if (left <= l && right >= r)
        {
            t[v] += val;
            lz[v] += val;
            return;
        }

        Push(v);

        int mid = (l + r) >> 1;
        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    void Update(int l, int r, int val)
    {
        Update(1, 1, n, l, r, val);
    }

    int GetMax()
    {
        return t[1];
    }
};

int const N = 3e5 + 5;
int const oo = 1e9 + 1;

int n, k;

vector<int> adj[N];
vector<int> nodes;

int d[N], h[N];
int in[N], out[N];

int cnt = 0;

SegmentTree it;

void BFS()
{
    memset(d, -1, sizeof d);

    queue<int> q;
    for (auto v : nodes) 
    {
        d[v] = 0;
        q.push(v);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) if (d[v] == -1)
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void DFSPrepare(int u, int p)
{
    in[u] = ++cnt;
    
    for (auto v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFSPrepare(v, u);
    }
    
    out[u] = cnt;
}

bool DFS(int u, int p, int bound)
{
    if (it.GetMax() <= bound) return true;

    for (auto v : adj[u]) if (v != p)
    {
        it.Update(1, n, 1);
        it.Update(in[v], out[v], -2);
        
        if (DFS(v, u, bound)) return true;
        
        it.Update(1, n, -1);
        it.Update(in[v], out[v], 2);
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    
    FOR(i, 1, k) 
    {
        int p; cin >> p;
        nodes.push_back(p);
    }
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    BFS();

    int l = 0;
    int r = n - 1;
    int res = n - 1;

    while (l <= r)
    {
        int mid = (l + r) >> 1;

        it = SegmentTree(n);
        FOR(u, 1, n) it.Update(in[u], in[u], d[u] <= mid && d[u] != -1 ? -oo : h[u]);

        if (DFS(1, -1, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}