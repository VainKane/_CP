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

int const N = 5e5 + 1;
int const oo = 2e9 + 9;

int n, m, s;

int a[N];
vector<int> adj[N];

bitset<N> mark;

int in[N], low[N];
int ccId[N];

vector<int> st;
int timer = 0;

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
        int v = 0;
        while (v != u)
        {
            a[u] += a[v];
            v = st.back(); st.pop_back();
            ccId[v] = u;

            if (mark[v]) mark[u] = true;
        }
    }
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (!in[u]) q.push(u);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        st.push_back(u);
        for (auto &v : adj[u]) if (!--in[v]) q.push(v);
    }
}

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
    }

    FOR(i, 1, n) cin >> a[i];

    int p; cin >> s >> p;
    while (p--)
    {
        int u; cin >> u;
        mark[u] = true;
    }

    FOR(u, 1, n) if (!in[u]) Tarjan(u, -1);
    FOR(u, 1, n) in[u] = 0;

    vector<int> e;

    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i], v = ccId[j];
        if (u == v) continue;

        st.push_back(u);
        e.push_back(v);
        in[v]++;
    }

    FOR(u, 1, n) adj[u].clear();
    REP(i, sz(e)) adj[st[i]].push_back(e[i]);
    
    e.clear();
    st.clear();
    BFS();

    FOR(i, 1, n) in[i] = -oo;
    in[ccId[s]] = a[ccId[s]];

    for (auto &u : st) for (auto &v : adj[u]) maxi(in[v], in[u] + a[v]);

    int res = 0;
    for (auto &u : st) if (mark[u]) maxi(res, in[u]);
    cout << res;

    return 0;
}