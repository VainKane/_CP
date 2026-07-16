#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAPDOI"

int const N = 1e5 + 5;

int n, k;
vector<int> adj[N];

long long bit[N];
bool used[N];

long long res = 0;

void Update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

long long Get(int idx)
{
    long long res = 0;

    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }

    return res;
}

long long Get(int l, int r)
{
    return Get(r) - Get(l - 1);
}

void DFS(int u)
{
    res += Get(max(u - k, 1), min(u + k, n));

    Update(u, 1);
    for (auto v : adj[u]) DFS(v);
    Update(u, -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        
        used[v] = true;
    }

    FOR(u, 1, n) if (!used[u]) 
    {
        DFS(u);
        break;
    }

    cout << res;

    return 0;
}