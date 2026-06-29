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

int const N = 1009;
int const Q = 1e5 + 5;
int const LOG = 20;

int n, q;

char a[N][N], b[N][N];
int x[Q], y[Q], u[Q], v[Q];
int res[Q];

vector<int> adj[N * N];
int id[N][N];

int up[2 * N * N][LOG];
int h[N * N], pos[N * N];
int timer = 0;

void BuildTree()
{
    memset(id, 0, sizeof id);
    FOR(i, 1, n * n) adj[i].clear();

    map<int, bool> mp;
    int timer = 0;
    
    FOR(i, 1, n) FOR(j, 1, n) if (a[i][j] == '#')
    {
        if (a[i][j - 1] == '.') id[i][j] = ++timer;
        else id[i][j] = id[i][j - 1];
    }

    int idx = 0;
    FOR(i, 2, n) FOR(j, 1, n) if (id[i][j])
    {
        if (id[i][j] != idx) idx = id[i][j], mp.clear();
        if (id[i - 1][j])
        {
            auto &c = mp[id[i - 1][j]];
            if (!c)
            {
                adj[id[i - 1][j]].push_back(idx);
                adj[idx].push_back(id[i - 1][j]);
            }

            c = true;
        }
    }
}

bool cmp(int u, int v) { return pos[u] < pos[v]; }
void DFS(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFS(v, u);
        up[++timer][0] = u;
    }
}

void InitLCA()
{
    timer = 0;
    DFS(1, -1);

    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(u, 1, timer - MK(j) + 1)
        up[u][j] = min(up[u][j - 1], up[u + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

int Dist(int u, int v) { return h[u] + h[v] - 2 * h[LCA(u, v)]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, '.', sizeof a);

    cin >> n >> q;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, q) cin >> x[i] >> y[i] >> u[i] >> v[i];

    BuildTree(), InitLCA();
    FOR(i, 1, q) res[i] += Dist(id[x[i]][y[i]], id[u[i]][v[i]]);

    FOR(i, 1, n) FOR(j, 1, n) b[n - j + 1][i] = a[i][j];
    FOR(i, 1, n) FOR(j, 1, n) a[i][j] = b[i][j];

    BuildTree(), InitLCA();
    FOR(i, 1, q) res[i] += Dist(id[n - y[i] + 1][x[i]], id[n - v[i] + 1][u[i]]);

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}