#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, k;
vector<pair<int, int>> adj[N];

bool mark[N];
long long s[N], f[N];

bool mark2[N];

void DFS(int u, int p)
{
    mark2[u] = mark[u];
    s[u] = f[u] = 0;

    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;
        if (v == p) continue;

        DFS(v, u);
        if (!mark2[v]) continue; 

        mark2[u] = true;
        maxi(f[u], f[v] + w);
        s[u] += s[v] + w;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 1, k)
    {
        int u; cin >> u;
        mark[u] = true;
    }    

    FOR(u, 1, n)
    {
        DFS(u, -1);
        cout << 2 * s[u] - f[u] << '\n';
    }

    return 0;
}
