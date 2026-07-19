#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
};

#define name "QKGRAPH"

int const N = 1e5 + 5;

int n;
int q;

Edge a[N];
Edge b[N];

int par[N];
int sz[N];

int res[N];

bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
}

void MakeSet()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
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

    if (sz[b] > sz[a]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        a[i] = {u, v, w};
    }


    for (int i = 1; i <= q; i++)
    {
        int k, v;
        cin >> k >> v;

        b[i] = {i, v, k};
    }

    sort(a + 1, a + n, cmp);
    sort(b + 1, b + q + 1, cmp);

    MakeSet();

    int j = 1;

    for (int i = 1; i <= q; i++)
    {
        while (j < n && a[j].w >= b[i].w)
        {
            Union(a[j].u, a[j].v);
            j++;
        }

        res[b[i].u] = sz[Find(b[i].v)] - 1;
    }

    for (int i = 1; i <= q; i++) cout << res[i] << '\n';

    return 0;
}