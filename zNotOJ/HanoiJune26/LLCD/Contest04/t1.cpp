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

int const N = 3e5 + 5;

int n, k;
vector<int> adj[N];

int up[2 * N][22];
int h[N], pos[N];

int in[N], node[N];
int timer = 0, haha = 0;

set<int> s;
int cost = 0;

bool cmp(int u, int v) { return pos[u] < pos[v]; }

void DFSPrepare(int u, int p)
{
    in[u] = ++haha;
    node[haha] = u;

    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFSPrepare(v, u);
        up[++timer][0] = u;
    }
}

void Build()
{
    DFSPrepare(1, -1);
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

void Update(int u, int delta)
{
    auto it = s.find(in[u]);
    if (sz(s) < 2) return;

    if (*it == *s.begin())
    {
        it++;
        cost += delta * Dist(u, node[*it]);
    }
    else if (*it == *s.rbegin())
    {
        it--;
        cost += delta * Dist(u, node[*it]);
    }
    else
    {
        it--;
        int v1 = node[*it];
        it++; it++;
        int v2 = node[*it];

        cost -= delta * Dist(v1, v2);
        cost += delta * Dist(u, v1) + delta * Dist(u, v2);
    }
}

void Add(int u)
{
    s.insert(in[u]);
    Update(u, 1);
}

void Del(int u)
{
    Update(u, -1);
    s.erase(in[u]);
}

int Get()
{
    if (s.empty()) return 0;
    return Dist(node[*s.begin()], node[*s.rbegin()]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Build();
    int res = 0;
    Add(1);

    for (int l = 1, r = 1; l <= n; l++)
    {
        for (; r <= n && cost + Get() <= 2 * (k - 1); r++)
        {
            maxi(res, r - l + 1);
            Add(r + 1);
        }

        Del(l);
    }

    cout << res;

    return 0;
}