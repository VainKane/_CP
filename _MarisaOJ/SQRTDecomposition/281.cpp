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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const BK = 314;
int const GR = N / BK + 5;
int const LOG = 18;

int n, q;
int a[N];

vector<int> adj[N];
int cnt[N];

int up[N][20];
int h[N];

int d[GR][N];
int id[N], cl[N];
int m = 0;

vector<int> vals;

void Compress()
{
    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
        cnt[a[i]]++;
    }

    FOR(i, 1, sz(vals)) if (cnt[i] > BK) 
    {
        id[i] = ++m;
        cl[id[i]] = i;
    }

    memset(cnt, 0, sizeof cnt);
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        FOR(i, 1, m) d[i][v] = d[i][u] + (a[v] == cl[i]);
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, LOG, 0) if (h[up[u][i]] >= h[v]) u = up[u][i];
    if (u == v) return u;

    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

void Clear(vector<int> &colors)
{
    for (auto &c : colors) cnt[c] = 0;
}

int QueryLight(int u, int v, int p, int exp)
{
    vector<int> colors = {a[p]};

    while (u != p)
    {
        colors.push_back(a[u]);
        if (++cnt[a[u]] == exp) return Clear(colors), vals[a[u] - 1];
        u = up[u][0];
    }

    while (v != p)
    {
        colors.push_back(a[v]);
        if (++cnt[a[v]] == exp) return Clear(colors), vals[a[v] - 1];
        v = up[v][0];
    }

    if (++cnt[a[p]] == exp) return Clear(colors), vals[a[p] - 1];
    return Clear(colors), -1;
}

int QueryHeavy(int u, int v, int p, int exp)
{
    FOR(i, 1, m) if (d[i][u] + d[i][v] - 2 * d[i][p] + (a[p] == cl[i]) >= exp) return vals[cl[i] - 1];
    return -1; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Compress();

    d[id[a[1]]][1] = 1;
    h[0] = -1;

    DFS(1, -1);

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int p = LCA(u, v);
        int len = h[u] + h[v] - 2 * h[p] + 1;
        int exp = len / 2 + 1;

        if (exp > BK) cout << QueryHeavy(u, v, p, exp) << '\n';
        else cout << QueryLight(u, v, p, exp) << '\n';
    }

    return 0;
}