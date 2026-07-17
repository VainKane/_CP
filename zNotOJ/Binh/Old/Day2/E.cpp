#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

struct SegmentTree
{
    vector<int> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.resize(4 * n);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int GetSum(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        int s1 = GetSum(2 * v, l, mid, left, right);
        int s2 = GetSum(2 * v, mid + 1, r, left, right);

        return s1 + s2;
    }

    void Update(int pos, int val)
    {
        Update(1, 1, n, pos, val);
    }

    int GetSum(int l, int r)
    {
        if (l > r) return 0;
        return GetSum(1, 1, n, l, r);
    }
};

int const N = 1e5 + 5;
int const LOG = 17;

int n, m, q;

int colour[N];
set<int> group[N];
vector<int> adj[N];

int h[N];
int up[N][20];

int in[N], out[N];
int timer = 0;

SegmentTree it;

void DFS(int u, int p)
{
    in[u] = ++timer;
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        DFS(v, u);
    }
    out[u] = timer;
}

void Init()
{
    DFS(1, -1);
    FOR(u, 1, n) FOR(i, 1, LOG)
        up[u][i] = up[up[u][i - 1]][i - 1];

    it = SegmentTree(n);
    
    FOR(c, 1, m)
    {
        group[c].insert(0);
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    FOR(i, 1, n) 
    {
        int c; cin >> c;
        colour[i] = c;
        group[c].insert(i);
    }
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Init();

    while (q--)
    {
        int type; cin >> type;

        if (type == 1)
        {

        }
    }

    return 0;
}