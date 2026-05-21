#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
    int w;
};

int const N = 509;
int const M = 5e4 + 10;

int n;
int m;

Edge a[M];
int parent[N];
int sz[N];

int preAns = -1;

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

void Sort(int k)
{
    int i = k;
    while (a[i].w < a[i - 1].w) 
    {
        swap(a[i], a[i - 1]);
        i--;
    }
}

int Kruskal(int k)
{
    int cnt = 0;
    MakeSet();

    Sort(k);

    int res = 0;

    for (int i = 1; i <= k; i++)
    {
        if (cnt == n - 1) break;

        if (Union(a[i].u, a[i].v))
        {
            a[++cnt] = a[i];
            res += a[i].w;
        }
    }

    if (cnt != n - 1) return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p = i;
        if (preAns != -1) p = n;

        cin >> a[p].u >> a[p].v >> a[p].w;
        preAns = Kruskal(p);
        cout << preAns << '\n';
    }

    return 0;
}