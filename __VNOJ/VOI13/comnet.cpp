#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
};

int const N = 1e5 + 5;
int const M = 1e6 + 5;

int t;
int n, m, q;
Edge a[M];
Edge b[M];

int par[N];
int sz[N];

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

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b) return false;

    if (sz[b] > sz[a]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];

    return true;
}

bool Solve(Edge x)
{
    MakeSet();

    for (int i = 1; i <= m; i++)
    {
        if (a[i].w >= x.w) continue;
        Union(a[i].u, a[i].v);
    }

    return !Union(x.u, x.v);
}

void Reset()
{
    for (int i = 1; i <= m; i++) a[i] = b[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    
    while (t--)
    {
        cin >> n >> m >> q;

        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            a[i] = {u, v, w};
            b[i] = a[i];
        }

        while (q--)
        {
            int k, s;
            cin >> k >> s;

            Reset();

            while (s--)
            {
                int t, c;
                cin >> t >> c;
                a[t].w = c;
            }

            cout << (Solve(a[k]) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}