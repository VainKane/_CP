#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;

struct Node
{
    int ind = 0;
    int val = 0;
};

int n;
int m;

vector<int> adj[N];
Node a[N];
bool visisted[N];
int parent[N];
int sz[N];
int res[N];

bool cmp(Node a, Node b)
{
    return a.val > b.val;
}

void MakeSet()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

int Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
    {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    return sz[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("20C.inp", "r", stdin);
    // freopen("20C.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i].ind = i;
        a[i].val = x;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(a + 1, a + n + 1, cmp);
    memset(res, -1, sizeof res);
    MakeSet();

    res[1] = a[1].val;
    for (int i = 1; i <= n; i++)
    {
        int u = a[i].ind;
        int val = a[i].val;
        visisted[u] = true;

        for (auto v : adj[u])
        {
            if (visisted[v])
            {
                int k = Union(u, v);
                res[k] = max(res[k], val);
            }
        }
    }

    for (int i = n; i >= 1; i--) res[i] = max(res[i], res[i + 1]);
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';

    return 0;
}