#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
int const oo = 1e9;
int const LOG = 20;

int n;
int a[N];
vector<int> adj[N];

int h[N];

int upPar[N][21];
int upMin[N][21];
int upMax[N][21];

void DFS(int u, int p)
{
    for (auto v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        upPar[v][0] = u;
        upMin[v][0] = upMax[v][0] = a[v];
    
        FOR(i, 1, n)
        {
            int &p = upPar[v][i - 1];
            upPar[v][i] = upPar[upPar[v][i - 1]][i - 1];
            upMin[v][i] = min(upMin[v][i - 1], upMin[p][i - 1]);
            upMax[v][i] = max(upMax[v][i - 1], upMax[p][i - 1]);
        }

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
        u = upPar[u][i];
    }

    if (u == v) return u;

    FORD(i, LOG, 0) if (upPar[u][i] != upPar[v][i])
    {
        u = upPar[u][i];
        v = upPar[v][i];
    }

    return upPar[u][0];
}

pair<int, int> GetPair(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    int mi = a[u];
    int ma = a[u];

    for (int tmp = delta; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        mini(mi, upMin[u][i]);
        maxi(ma, upMax[u][i]);
    }

    return {mi, ma};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    long long res = 0;

    FOR(u, 1, n) FOR(v, u + 1, n)
    {
        int p = LCA(u, v);
        pair<int, int> p1 = GetPair(u, p);
        pair<int, int> p2 = GetPair(v, p);

        res += max(p1.S, p2.S) - min(p1.F, p2.F);
    }

    cout << res;

    return 0;
}