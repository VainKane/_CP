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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;

struct SegmentTree
{
    vector<int> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] += val;
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid) Update(v << 1, l, mid, pos, val);
        else Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        int mid = l + r >> 1;
        int val1 = Get(v << 1, l, mid, left, right);
        int val2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return max(val1, val2);
    }

    void Update(int pos, int val) { Update(1, 1, n, pos, val); }
    int Get(int l, int r) { return Get(1, 1, n, l, r); }
};

int n;
vector<int> adj[N];

int sz[N], bigChild[N];
int pos[N], par[N];
int head[N];
int timer = 0;

SegmentTree it;

void DFSPrepare(int u, int p)
{
    head[u] = u;
    sz[u] = 1;
    int mx = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        par[v] = u;
        DFSPrepare(v, u);
        if (maxi(mx, sz[v])) bigChild[u] = v;
        sz[u] += sz[v];
    }
}

void DFS(int u, int p)
{
    pos[u] = ++timer;
    if (bigChild[u])
    {
        head[bigChild[u]] = head[u];
        DFS(bigChild[u], u);
    }

    for (auto &v : adj[u]) if (v != p && v != bigChild[u]) DFS(v, u);
}

int LCA(int u, int v)
{
    while (head[u] != head[v])
    {
        if (pos[u] > pos[v]) u = par[head[u]];
        else v = par[head[v]];
    }

    return pos[u] < pos[v] ? u : v;
}

int Query(int u, int p)
{
    int res = 0;
    while (head[u] != head[p])
    {
        maxi(res, it.Get(pos[head[u]], pos[u]));
        u = par[head[u]];
    }

    return max(res, it.Get(pos[p], pos[u]));
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    it = SegmentTree(n);

    int q; cin >> q;
    while (q--)
    {
        char type;
        int u, v;

        cin >> type >> u >> v;
        if (type == 'I') it.Update(pos[u], v);
        else
        {
            int p = LCA(u, v);
            cout << max(Query(u, p), Query(v, p)) << '\n';
        }
    }

    return 0;
}