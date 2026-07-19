#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "TREEDATA"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5009;
int const LOG = 17;

int n;

vector<pair<int, int>> adj[N];
bool mark[N];

int up[N][20];
int in[N];

int h[N];
long long d[N];

int timer = 0;

void DFS(int u, int p)
{
    in[u] = ++timer;
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;
        d[v] = d[u] + w;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);

    FORD(i, LOG, 0) if (up[u][i] && h[up[u][i]] >= h[v]) u = up[u][i];
    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

bool cmp1(int u, int v)
{
    return in[u] < in[v];
}

bool cmp2(int u, int v)
{
    return in[u] > in[v];
}

long long Dist(int u, int v)
{
    return d[u] + d[v] - 2 * d[LCA(u, v)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n)
    {
        char ch; cin >> ch;
        mark[i] = ch - '0';
    }

    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1, -1);

    int q; cin >> q;
    while (q--)
    {
        int type, u;
        cin >> type >> u;

        if (type == 1) mark[u] ^= 1;
        else if (type == 2)
        {
            vector<int> v;
            FOR(u, 1, n) if (mark[u]) v.push_back(u);

            sort(all(v), cmp1);
            v.push_back(v[0]);

            long long res = 0;
            FOR(i, 1, sz(v) - 1) res += Dist(v[i], v[i - 1]);
            cout << res << '\n';
        }
        else if (type == 3)
        {
            vector<int> v;
            FOR(u, 1, n) if (mark[u]) v.push_back(u);

            long long res = 0, tmp = 0;

            sort(all(v), cmp1);
            FOR(i, 1, sz(v) - 1) res += Dist(v[i], v[i - 1]);

            sort(all(v), cmp2);
            FOR(i, 1, sz(v) - 1) tmp += Dist(v[i], v[i - 1]);
        }
    }


    return 0;
}
