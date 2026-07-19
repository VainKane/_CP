#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
    int w;
};

int const N = 1009;

int n;
int m;

Edge a[10009];
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

int Kruskal2(int e)
{
    vector<int> mst;
    int d = 0;

    MakeSet();
    for (int i = 1; i <= m; i++)
    {
        if (mst.size() == n - 1) break;
        
        if (i != e)
        {
            if (Union(a[i].u, a[i].v))
            {
                mst.push_back(i);
                d += a[i].w;
            }
        }
    }

    if (mst.size() != n - 1) return 1e9;
    return d;
}

void Kruskal()
{
    vector<int> mst;
    int d = 0;
    int s = 1e9;

    sort(a + 1, a + m + 1, cmp);
    MakeSet();

    for (int i = 1; i <= m; i++)
    {
        if (mst.size() == n - 1) break;
        
        if (Union(a[i].u, a[i].v))
        {
            mst.push_back(i);
            d += a[i].w;
        }
    }

    for (auto e : mst)
    {
        s = min(s, Kruskal2(e));
    }

    cout << d << ' ' << s;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }

    Kruskal();

    return 0;
}