#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
    int w;
};

int const N = 30009;
int parent[N];
Edge a[(int)1e5 + 10];

int n;
int m;

void MakeSet()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
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
    parent[b] = a;
    return true;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void Krusal()
{
    vector<int> mst;
    int d = 0;
    
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

    cout << d;
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

    Krusal();

    return 0;
}