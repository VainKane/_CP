#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
    double w;
};

int const N = 5005;
int const NN = 12497509;

int n;
int m;

pair<int, int> v[N + 5];
Edge a[NN];
bool built[N][N];
int k = 0;
int cnt = 0;

int parent[N];
int sz[N];

double GetLength(int x1, int y1, int x2, int y2)
{
    int a = x1 - x2;
    int b = y1 - y2;
    return sqrt(a * a + b * b);
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

void Kruskal()
{
    vector<int> mst;
    long double d = 0;

    sort(a + 1, a + k + 1, cmp);
    MakeSet();

    for (int i = 1; i <= k; i++)
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

    freopen("21B.inp", "r", stdin);

    cout << fixed << setprecision(2);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        built[u][v] = true;
        built[v][u] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ++k;
            a[k].u = i;
            a[k].v = j;
            a[k].w = GetLength(v[i].first, v[i].second, v[j].first, v[j].second);

            if (built[i][j]) a[k].w = 0;
        }
    }

    Kruskal();

    return 0;
}