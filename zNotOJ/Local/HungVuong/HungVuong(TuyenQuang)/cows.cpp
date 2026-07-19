#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define name "cows"

int const N = 1e6 + 5;

int n, m, k;

int par[N];
int sz[N];

bool used[N];
int res = 0;

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

    cin >> n >> m >> k;
    MakeSet();

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    for (int i = 1; i <= k; i++) 
    {
        int x; cin >> x;
        used[Find(x)] = true;
    }

    for (int u = 1; u <= n; u++)
    {
        int p = Find(u);
        if (!used[p]) res += sz[p];
        used[p] = true;
    }

    cout << res;

    return 0;
}