#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const oo = 1e9;
int const MOD = 1e9 + 7;

int n, m;
int a[N];
vector<int> adj[N];

int in[N], low[N];
int cnt = 0, scc = 0;

int sccId[N];
int f[N], g[N];

stack<int> st;

void Tarjan(int u)
{
    low[u] = in[u] = ++cnt;
    st.push(u);

    for (auto &v : adj[u])
    {
        if (sccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v);
            mini(low[u], low[v]);
        }
    }

    if (low[u] == in[u])
    {
        int v = 0;
        scc++;

        while (v != u)
        {
            v = st.top();
            st.pop();
            sccId[v] = scc;

            if (mini(f[scc], a[v])) g[scc] = 1;
            else if (f[scc] == a[v]) g[scc]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(f, 0x3f, sizeof f);
    FOR(u, 1, n) if (!in[u]) Tarjan(u);

    long long cost = 0;
    int ways = 1;

    FOR(i, 1, scc)
    {
        cost += f[i];
        ways = 1ll * ways * g[i] % MOD;
    }

    cout << cost << ' ' << ways;

    return 0;
}