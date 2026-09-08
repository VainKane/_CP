#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
    int w;  
};

int const N = 500;
int const M = 5e4 + 10;

int n;
int m;

Edge a[M];
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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int Kruskal(int k)
{
    vector<int> mst;
    int res = 0;

    MakeSet();
    sort(a + 1, a + k + 1, cmp);

    for (int i = 1; i <= k; i++)
    {
        if (mst.size() == n - 1) break;

        if (Union(a[i].u, a[i].v))
        {
            mst.push_back(i);
            res += a[i].w;
        }
    }

    if (mst.size() != n - 1) return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        cout << Kruskal(i) << '\n';
    }

    return 0;
}