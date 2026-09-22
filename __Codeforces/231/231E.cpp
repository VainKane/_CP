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

int const N = 1e5 + 5;
int const LOG = 20;
int const MOD = 1e9 + 7;

int n, m;
vector<int> adj[N];
vector<int> cadj[N];

int in[N], low[N];
int ccId[N];

vector<int> st;
int timer = 0, cc = 0;

int up[LOG][2 * N];
int pos[N], d[N];

bool lmao[N];
int pw[N];

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push_back(u);
    for (auto &v : adj[u])
    {
        if (v == p || ccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]);
        }
    }

    if (low[u] == in[u])
    {
        int v = 0; cc++;
        int haha = 0;

        while (v != u)
        {
            v = st.back(); st.pop_back();
            ccId[v] = cc;
            haha++;
        }

        lmao[cc] = haha > 1;
    }
}

bool cmp(int u, int v) { return pos[u] < pos[v]; }

void DFS(int u, int p)
{
    up[0][++timer] = u;
    pos[u] = timer;

    for (auto &v : cadj[u]) if (v != p)
    {
        d[v] = d[u] + lmao[v];
        DFS(v, u);
        up[0][++timer] = u;
    }
}

void Build()
{
    pw[0] = 1;
    FOR(i, 1, n) pw[i] = pw[i - 1] * 2 % MOD;

    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[j][i] = min(up[j - 1][i], up[j - 1][i + MK(j - 1)], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[k][u], up[k][v - MK(k) + 1], cmp);
}

int Dist(int u, int v) { return d[u] + d[v] - 2 * d[LCA(u, v)] + lmao[LCA(u, v)]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tarjan(1, -1);
    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i], v = ccId[j];
        if (u != v) cadj[u].push_back(v);
    }

    timer = 0;
    DFS(1, -1);
    Build();

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        u = ccId[u], v = ccId[v];
        cout << pw[Dist(u, v)] << '\n';
    }

    return 0;
}