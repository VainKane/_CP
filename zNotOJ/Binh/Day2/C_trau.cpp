#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;

int n;
vector<int> adj[N];

int f1[N], f2[N];
int f[N];

void DFS(int u, int p)
{
    f1[u] = f2[u] = f[u] = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        
        if (f1[v] + 1 > f1[u])
        {
            f2[u] = f1[u];
            f1[u] = f1[v] + 1;
        }
        else maxi(f2[u], f1[v] + 1);

        maxi(f[u], max(f1[u] + f2[u], f[v]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = n - 1;

    FOR(u, 1, n) for (auto &v : adj[u])
    {
        DFS(u, v);
        int d1 = f[u];

        DFS(v, u);
        int d2 = f[v];

        // cout << u << ' ' << v << ' ' << d1 << ' ' << d2 << '\n';

        mini(res, max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1}));
    }

    cout << res;

    return 0;
}