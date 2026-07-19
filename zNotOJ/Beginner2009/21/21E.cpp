#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
    int w;
};

int const N = 1e5 + 10;
int const M = 1e6 + 10;

int t;
int n;
int m;
int q;

Edge a[M];
Edge b[M];
int parent[N];
int sz[N];

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

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b) return false;

    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];

    return true;
}

void Reset()
{
    for (int i = 1; i <= m; i++)
    {
        a[i] = b[i];
    }
}

bool Solve(int k)
{
    MakeSet();

    for (int i = 1; i <= m; i++) 
    {
        if (a[i].w >= a[k].w) continue;
        Union(a[i].u, a[i].v);
    }

    return !Union(a[k].u, a[k].v);
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
            cin >> a[i].u >> a[i].v >> a[i].w;
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

            if (Solve(k)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}