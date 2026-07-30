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
int const M = 1e5 + 5;
int const LOG = 20;
int const BK = 223;
int bkId[2 * N];

struct Query
{
    int u, v, p, id;
    Query(int _u = 0, int _v = 0, int _p = 0, int _id = 0) { u = _u, v = _v, p = _p, id = _id; }
    bool operator < (Query const other) const
    {
        if (bkId[u] != bkId[other.u]) return bkId[u] < bkId[other.u];
        return v < other.v;
    }
};

int n, q;

int a[N];
vector<int> adj[N];
Query qr[N];

int in[N], out[N];
int node[2 * N];

int up[2 * N][LOG];
int pos[N];
int timer = 0, haha = 0;

vector<int> facts[M];
bool prime[M];

bool mark[N];
int cnt[M];

int res[N];
int cur = 0;

void Sieve()
{
    int lim = *max_element(a + 1, a + n + 1);
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, lim) if (prime[i]) for (int j = i; j <= lim; j += i)
    {
        facts[j].push_back(i);
        prime[j] = false;
    }
}

bool cmp(int u, int v) { return pos[u] < pos[v]; }

void DFS(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;

    up[++haha][0] = u;
    pos[u] = haha;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        up[++haha][0] = u;
    }
    
    out[u] = ++timer;
    node[timer] = u;
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

void Init()
{
    FOR(i, 1, 2 * n) bkId[i] = (i - 1) / BK + 1;

    FOR(j, 1, 31 - __builtin_clz(haha)) FOR(i, 1, haha - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

void Update(int &val, int delta)
{
    cnt[val] += delta;
    cur += cnt[val] == 1 && delta == 1;
    cur -= cnt[val] == 0;
}

void Toggle(int &u)
{
    mark[u] ^= 1;
    for (auto &x : facts[a[u]]) Update(x, mark[u] ? 1 : -1);
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

    Sieve();
    DFS(1, -1);
    Init();

    FOR(i, 1, q)
    {
        int u, v;
        cin >> u >> v;
        
        if (in[u] > in[v]) swap(u, v);

        int p = LCA(u, v);
        if (p == u) qr[i] = {in[u], in[v], 0, i};
        else qr[i] = {out[u], in[v], p, i};
    }

    sort(qr + 1, qr + q + 1);

    int l = 1, r = 0;
    FOR(i, 1, q)
    {
        while (r < qr[i].v) Toggle(node[++r]);
        while (r > qr[i].v) Toggle(node[r--]);

        while (l > qr[i].u) Toggle(node[--l]);
        while (l < qr[i].u) Toggle(node[l++]);

        Toggle(qr[i].p);
        res[qr[i].id] = cur;
        Toggle(qr[i].p);
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}