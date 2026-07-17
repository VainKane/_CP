#include <bits/stdc++.h>

using namespace std;

#define name "query"

int const N = 3e5 + 5;
int const oo = 21e8;

struct Node
{
    int x[16];

    Node()
    {
        memset(x, -0x7f, sizeof x);
    }
};

Node Merge(Node a, Node b)
{
    Node res;
    int l = 1, r = 1;

    for (int i = 1; i <= 15; i++)
    {
        if (a.x[l] > b.x[r]) res.x[i] = a.x[l++];
        else res.x[i] = b.x[r++];
    }

    return res;
}

struct SegmentTree
{
    Node t[4 * N];
    int lz[4 * N];

    Node empty;

    void Add(int v, int &val)
    {
        for (int i = 1; i <= 15; i++)
        {
            if (t[v].x[i] < -oo) break;
            t[v].x[i] += val;
        }
    }

    void Build(int v, int l, int r)
    {
        if (l == r) 
        {
            t[v].x[1] = 0;
            return;
        }

        int mid = l + (r - l) / 2;

        Build(2 * v, l, mid);
        Build(2 * v + 1, mid + 1, r);

        t[v] = Merge(t[2 * v], t[2 * v + 1]);
    }

    void Push(int &v)
    {
        if (lz[v])
        {
            Add(2 * v, lz[v]);
            Add(2 * v + 1, lz[v]);
            lz[2 * v] += lz[v];
            lz[2 * v + 1] += lz[v];

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int &left, int &right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            Add(v, val);
            lz[v] += val; 
            return;
        }

        Push(v);
        int mid = l + (r - l) / 2;

        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = Merge(t[2 * v], t[2 * v + 1]);
    }

    Node Get(int v, int l, int r, int &left, int &right)
    {
        if (l > right || r < left) return empty;
        if (left <= l && right >= r) return t[v];

        Push(v);
        int mid = l + (r - l) / 2;

        Node m1 = Get(2 * v, l, mid, left, right);
        Node m2 = Get(2 * v + 1, mid + 1, r, left, right);

        return Merge(m1, m2);
    }
};

int t;
int n, q;
vector<int> adj[N];

bool odd[N];

int l1[N], r1[N];
int l0[N], r0[N];

int cnt1 = 0, cnt0 = 0;

SegmentTree t1;
SegmentTree t0;

void DFS(int u, int p)
{
    if (odd[u]) l1[u] = ++cnt1;
    else l0[u] = ++cnt0;

    for (auto v : adj[u]) 
    {
        if (v == p) continue;

        odd[v] = !odd[u];
        DFS(v, u);
        l1[u] = min(l1[u], l1[v]);
        l0[u] = min(l0[u], l0[v]);
    }

    r1[u] = cnt1;
    r0[u] = cnt0;
}

void Init()
{
    for (int u = 1; u <= n; u++) l1[u] = l0[u] = n + 1;
    odd[1] = 1;
    
    DFS(1, -1);

    t1.Build(1, 1, cnt1);
    t0.Build(1, 1, cnt0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t >> n;
    for (int i = 2; i <= n; i++)
    {
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    Init();

    cin >> q;

    while (q--)
    {
        string type; cin >> type;

        if (type == "get")
        {
            int u; cin >> u;

            if (odd[u]) cout << t1.Get(1, 1, cnt1, l1[u], l1[u]).x[1] << ' ';
            else cout << t0.Get(1, 1, cnt0, l0[u], l0[u]).x[1] << ' ';

            continue;
        }

        int u, k;
        cin >> u >> k;

        if (type == "add")
        {
            if (!odd[u]) k = -k;

            if (l1[u] <= r1[u]) t1.Update(1, 1, cnt1, l1[u], r1[u], k);
            if (l0[u] <= r0[u]) t0.Update(1, 1, cnt0, l0[u], r0[u], -k);
        }
        else if (type == "pos")
        {
            Node m1, m0;
            if (l1[u] <= r1[u]) m1 = t1.Get(1, 1, cnt1, l1[u], r1[u]);
            if (l0[u] <= r0[u]) m0 = t0.Get(1, 1, cnt0, l0[u], r0[u]);

            int res = Merge(m1, m0).x[k];
            if (res < -oo) res = 0;
            
            cout << res << ' ';
        }
    }

    return 0;
}