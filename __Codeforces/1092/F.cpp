#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n;
int a[N];

vector<int> adj[N];

long long sum = 0;

long long s[N];
long long f[N], fPar[N];

void DFSPrepare(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        s[u] += s[v];
        f[u] += f[v] + s[v];
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        fPar[v] = fPar[u] + f[u] - f[v] - s[v] + sum - s[v];
        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i], sum += s[i];

    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    long long res = 0;
    FOR(u, 1, n) maxi(res, f[u] + fPar[u]);
    cout << res;

    return 0;
}