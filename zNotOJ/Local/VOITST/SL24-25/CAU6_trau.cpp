#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU6"

int const N = 2e5 + 5;
int const MOD = 1e9 + 7;

int n;
vector<int> adj[N];

int f[N];
int in[N];

int pw[N];
int sz[N];

int timer = 0;

void DFS(int u, int p)
{
    sz[u] = f[u] = 1;

    for (auto v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] = 1ll * f[u] * (f[v] + 1) % MOD;
    }
}

void DFSTime(int u, int p)
{
    in[u] = ++timer;
    for (auto v : adj[u]) if (v != p) DFSTime(v, u);
}

bool CheckSub1()
{
    FOR(u, 1, n) if (adj[u].size() > 2 || adj[u].size() == 0) return false;
    return true;
}

void Sub1()
{
    FOR(u, 1, n) if (adj[u].size() == 1)
    {
        DFSTime(u, -1);
        break;
    }
    FOR(u, 1, n)
    {
        int x = 1ll * in[u] * (n - in[u] + 1) % MOD;
        cout << x << ' ';
    }
    exit(0);
}

bool CheckSub2()
{
    FOR(i, 2, n)
        if (adj[i].size() != 1 || adj[i][0] != 1) return false;
    return true;
}

void Sub2()
{
    pw[0] = 1;
    FOR(i, 1, n) pw[i] = 1ll * pw[i - 1] * 2 % MOD;

    cout << pw[n - 1] << ' ';
    FOR(i, 2, n) cout << (pw[n - 2] + 1) % MOD << ' ';
}

void Sub3()
{
    FOR(i, 1, n)
    {
        DFS(i, -1);
        cout << 1ll * f[i] * pw[n - sz[i]] % MOD << ' ';
    }
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (CheckSub1()) Sub1();
    else if (CheckSub2()) Sub2();
    else Sub3();

    return 0;
}
