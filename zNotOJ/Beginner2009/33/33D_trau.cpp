#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 5;

int n;
int m;
vector<int> adj[N];

int par[N];
int sz[N];

pair<int, int> res;

bool visisted[N];

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

void Update(int u, int child)
{
    if (res.first < child) res = {child, u};
    else if (res.first == child) res.second = min(res.second, u);
}

void Cal(int x)
{
    MakeSet();
    int cnt = 0;

    for (int u = 1; u <= n; u++)
    {
        if (u == x) continue;
        for (auto v : adj[u])
        {
            if (v == x) continue;
            Union(v, u);
        } 
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == x) continue;
        if (i == Find(i)) cnt++; 
    }

    Update(x, cnt);
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) Cal(i);
    cout << res.first << ' ' << res.second;

    return 0;
}