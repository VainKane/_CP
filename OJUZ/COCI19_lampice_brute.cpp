#include <bits/stdc++.h>

#define For(i, a, b) for (int i=a;i<=b;++i)

using namespace std;

const int N = 200005;
const long long base = 35711;
const long long mod  = 1e9 + 7;

int n, Len, maxDep, child[N], valid[N];
char a[N];

vector<pair<int, long long>> b;
long long pw[N];
vector<int> adj[N];
unordered_map<long long, bool> f[N];

void countChild(int u, int p)
{
    child[u] = 1;
    for (int v : adj[u]) if (v != p && valid[v])
    {
        countChild(v, u);
        child[u] += child[v];
    }
}

bool dfs(int u, int p, int h, long long hshdown, long long hshup)
{
    if (h > Len) return false;

    if (p)
        hshdown = (hshdown * base + a[u]) % mod;
    hshup = (hshup + 1LL * a[u] * pw[h - 1]) % mod;

    long long x =  (hshup * pw[Len - h] - hshdown + mod) % mod;
    if (!p) f[h][x] = true;

    if (f[Len - h + 1].find(x) != f[Len - h + 1].end() )
        return true;

    for (int v : adj[u]) if (v != p && valid[v])
    {
        if (!p) b.clear();

        if (dfs(v, u, h + 1, hshdown, hshup))
            return true;

        if (!p)
            for (pair<int, long long> x : b) f[x.first][x.second] = true;
    }

    maxDep = max(maxDep, h);
    b.push_back({h, x});

    return false;
}

bool CD(int u, int n)
{
    countChild(u, 0);

    int flag = 1, half = n / 2;
    while (flag)
    {
        flag = 0;
        for (int v : adj[u])
            if (valid[v] && child[v] < child[u] && child[v] > half)
            {
                u = v;
                flag = 1;
                break;
            }
    }

    countChild(u, 0);

    if (dfs(u, 0, 1, 0, 0)) return true;

    For(i, 1, maxDep) f[i].clear();
    maxDep = 0;

    valid[u] = false;
    for (int v : adj[u]) if (valid[v])
        if (CD(v, child[v])) return true;
    return false;
}

bool check(int len)
{
    Len = len;
    For(i, 1, n) valid[i] = 1, f[i].clear();
    return CD(1, n);
}

void solve()
{
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n - 1)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pw[0] = 1;
    For(i, 1, n) pw[i] = pw[i - 1] * base % mod;

    int l = 0, r = (n - 1) / 2;
    while (l < r)
    {
        int g = (l + r + 1) / 2;
        if (check(g * 2 + 1)) l = g; else r = g - 1;
    }

    int ans = r * 2 + 1;

    l = 0, r = n / 2;
    while (l < r)
    {
        int g = (l + r + 1) / 2;
        if (check(g * 2)) l = g; else r = g - 1;
    }

    cout << max(ans, r * 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    solve();

    return 0;
}