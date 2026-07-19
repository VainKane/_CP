#include <bits/stdc++.h>

using namespace std;

#define name "costquery"

struct Edge
{
    int u, v, w;
};

int const N = 1e5 + 5;

int n, q;
Edge a[N];

int par[N];
int sz[N];

long long cnt[N];

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
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
    if (v == par[v]) return v;
    return par[v] = Find(par[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);
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

    MakeSet();

    sort(a + 1, a + n, cmp);
    for (int i = 1; i < n; i++)
    {
        cnt[i] = 1ll * sz[Find(a[i].u)] * sz[Find(a[i].v)];
        cnt[i] += cnt[i - 1];
        
        Union(a[i].u, a[i].v);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        l = lower_bound(a + 1, a + n, Edge {0, 0, l}, cmp) - a;
        r = upper_bound(a + 1, a + n, Edge {0, 0, r}, cmp) - a - 1;

        cout << cnt[r] - cnt[l - 1] << ' ';
    }

    return 0;
}