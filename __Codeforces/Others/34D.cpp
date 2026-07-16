#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 5e4 + 5;

int n, r1, r2;
vector<int> adj[N];

int par[N];

void DFS(int u)
{
    for (auto v : adj[u]) if (v != par[u])
    {
        par[v] = u;
        DFS(v);   
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> r1 >> r2;
    FOR(i, 1, n)
    {
        if (i == r1) i++;
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    DFS(r2);

    FOR(i, 1, n) if (i != r2) cout << par[i] << ' ';

    return 0;
}