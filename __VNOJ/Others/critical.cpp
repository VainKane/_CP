#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e4 + 5;

int n, m;
vector<int> adj[N];

int f[N];

int id[N], low[N];
int timer = 0, cnt = 0;

int cc[N];
int ccId[N];
bool cut[N];

void Tarjan(int u, int p, int idx)
{
    int child = (p != -1);
    low[u] = id[u] = ++timer;
    f[u] = 1;

    cc[idx]++;
    ccId[u] = idx;

    int sum = 0;
    long long pairs = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        if (id[v]) mini(low[u], id[v]);
        else
        {
            Tarjan(v, u, idx);

            mini(low[u], low[v]);
            f[u] += f[v];

            child += low[v] >= id[u];
        }        
    }

    cut[u] = child >= 2;
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
        adj[v].push_back(u);
    }

    FOR(u, 1, n) if (!id[u]) Tarjan(u, -1, ++cnt);

    long long res = 0;
    FOR(u, 1, n) if (cut[u]) for (auto &v : adj[u]) res += 1LL * f[v] * (cc[ccId[u]] - f[v]);

    cout << fixed << setprecision(10) << (double)res / n;

    return 0;
}