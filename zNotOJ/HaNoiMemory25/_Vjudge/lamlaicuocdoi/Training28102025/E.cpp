#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

int const N = 1e5 + 5;
int const LOG = 17;

int n;
vector<int> adj[N];

int up[N][20];
int h[N];

int in[N];
int cnt = 0;

long long res[N];

void DFS(int u, int p)
{
    in[u] = ++cnt;
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        u = up[u][i];
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int Dist(int u, int v)
{
    return h[u] + h[v] - 2 * h[LCA(u, v)];
}

bool cmp(int u, int v)
{
    return in[u] < in[v];
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

    DFS(1, -1);

    FORD(i, n, 1)
    {
        vector<int> v;
        for (int j = i; j <= n; j += i) v.push_back(j);
        sort(all(v), cmp);

        v.push_back(1);
        res[i] = Dist(1, v[0]);
        FOR(j, 1, sz(v) - 1) res[i] += Dist(v[j], v[j - 1]);
    }

    FOR(i, 1, n) cout << res[i] << '\n';

    return 0;
}