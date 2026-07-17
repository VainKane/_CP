#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

struct Edge
{
    int u, v;
};

struct Query
{
    int x, y, z;
};

int const N = 1e5 + 5;

int n, m, q;

Edge a[N];
Query qr[N];

vector<int> group[N];
pair<int, int> bd[N];
int res[N];

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

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int GetSize(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b) return sz[a];
    return sz[a] + sz[b];
}

void Reset()
{
    for (int i = 1; i <= m; i++) group[i].clear();
    MakeSet();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
    }

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        qr[i] = {x, y, z};
    }

    for (int i = 1; i <= q; i++) bd[i] = {1, m};

    for (int haha = 1; haha <= 17; haha++)
    {
        Reset();

        for (int i = 1; i <= q; i++)
        {
            if (bd[i].F > bd[i].S) continue;

            int mid = (bd[i].F + bd[i].S) / 2;
            group[mid].push_back(i);
        }

        for (int mid = 1; mid <= m; mid++)
        {
            Union(a[mid].u, a[mid].v);

            for (auto i : group[mid])
            {
                if (GetSize(qr[i].x, qr[i].y) >= qr[i].z)
                {
                    res[i] = mid;
                    bd[i].S = mid - 1;
                }
                else bd[i].F = mid + 1;
            }
        }
    }

    for (int i = 1; i <= q; i++) cout << res[i] << '\n';

    return 0;
}