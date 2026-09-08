#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n, q;
int pw[N];

vector<pair<int, int>> adj[N];
int color[N];

bool DFS(int u)
{
    for (auto e : adj[u])
    {
        int v = e.F;
        int x = e.S;

        if (color[v] == -1)
        {
            color[v] = color[u] ^ x;
            if (!DFS(v)) return false;
        }
        else if ((color[u] ^ color[v]) != x) return false;
    }
    return true;
}

int Solve()
{
    int cc = 0;
    FOR(u, 1, n) if (color[u] == -1)
    {
        cc++;
        color[u] = 0;
        if (!DFS(u)) return 0;
    }

    return pw[cc - 1];
}

void Reset()
{
    FOR(i, 1, n) adj[i].clear();
    memset(color, -1, sizeof color);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pw[0] = 1;
    FOR(i, 1, 1e5) pw[i] = 1ll * pw[i - 1] * 2 % MOD;

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> q;
        Reset();

        FOR(i, 2, n)
        {
            int u, v; 
            cin >> u >> v;
        }
        FOR(i, 1, q)
        {
            int u, v, x;
            cin >> u >> v >> x;
            adj[u].push_back({v, x});
            adj[v].push_back({u, x});
        }

        cout << Solve() << '\n';
    }

    return 0;
}