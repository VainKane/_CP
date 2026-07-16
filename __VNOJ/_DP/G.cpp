#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class X, class Y>
    bool maxi(X &x, Y const &y)
    {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

int const N = 1e5 + 5;

int n, m;
vector<int> adj[N];

int f[N];

int DFS(int u)
{
    if (f[u]) return f[u];
    for (auto v : adj[u])
    {
        DFS(v);
        maxi(f[u], f[v] + 1);
    }
    return f[u];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    FOR(u, 1, n) f[u] = DFS(u);
    cout << *max_element(f + 1, f + n + 1);

    return 0;
}