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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e4 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];

    Hash() { memset(x, 0, sizeof x); }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return x[k] < other.x[k];
        return false;
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

int n;
vector<int> adj[N];
char s[N];

int sz[N];
bool del[N];

int h[N];

int pw[NMOD][N];
Hash hs1[N], hs2[N];

int in[N], out[N];
int node[N];
int timer = 0;

set<pair<int, Hash>> st;

void Init()
{
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n) pw[k][i] = 1LL * pw[k][i - 1] * BASE % MODS[k];
    }
}

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p && !del[v])
    {
        DFSPrepare(v, u);
        sz[u] += sz[v];
    }
}

int Centroid(int u, int p, int n)
{
    for (auto &v : adj[u]) if (v != p && !del[v] && sz[v] > n / 2) return Centroid(v, u, n);
    return u;
}

void DFS(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;

    for (auto &v : adj[u]) if (v != p && !del[v])
    {
        h[v] = h[u] + 1;
        REP(k, NMOD)
        {
            hs1[v].x[k] = (hs1[u].x[k] + 1LL * pw[k][h[v]] * s[v]) % MODS[k];
            hs2[v].x[k] = (1LL * hs2[u].x[k] * BASE + s[v]) % MODS[k];
        }

        DFS(v, u);
    }

    out[u] = timer;
}

Hash Val(int u, int len)
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = (hs2[u].x[k] - 1LL * hs1[u].x[k] * pw[k][len - h[u] - 1]) % MODS[k];
        if (tmp < 0) tmp += MODS[k];
        res.x[k] = tmp;
    }
    
    return res;
}

bool Solve(int u, int len)
{
    DFSPrepare(u, -1);
    int cen = Centroid(u, -1, sz[u]);

    del[cen] = true;
    h[cen] = timer = 0;
    
    REP(k, NMOD) hs1[cen].x[k] = s[cen];
    hs2[cen] = Hash();
    st.clear();

    DFS(cen, -1);
    st.insert({0, Val(cen, len)});

    for (auto &v : adj[cen]) if (!del[v])
    {
        FOR(i, in[v], out[v]) if (h[node[i]] <= len - 1 && st.count({len - 1 - h[node[i]], Val(node[i], len)})) return true;
        FOR(i, in[v], out[v]) if (h[node[i]] <= len - 1) st.insert({h[node[i]], Val(node[i], len)});
    }

    for (auto &v : adj[cen]) if (!del[v] && Solve(v, len)) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Init();
    int res = 1;
    
    int l = 1, r = n / 2;
    while (l <= r)
    {
        int mid = l + r >> 1;
        memset(del, 0, sizeof del);

        if (Solve(1, 2 * mid)) l = mid + 1, maxi(res, 2 * mid);
        else r = mid - 1;
    }

    l = 1, r = n / 2;
    while (l <= r)
    {
        int mid = l + r >> 1;
        memset(del, 0, sizeof del);

        if (Solve(1, 2 * mid + 1)) l = mid + 1, maxi(res, 2 * mid + 1);
        else r = mid - 1;
    }

    cout << res;

    return 0;
}