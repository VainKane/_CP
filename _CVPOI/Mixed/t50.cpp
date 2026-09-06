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

int n, m, a, b;
vector<ii> adj[N], bridgeAdj[N];

int in[N], low[N];
int timer = 0, cc = 0;

int ccId[N];
vector<int> st;

bool val[N], d[N];
bool visited[N];

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push_back(u);

    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p) continue;
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
        while (v != u)
        {
            v = st.back(); st.pop_back();
            ccId[v] = cc;
        }
    }
}

void BFS(int s)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;
    d[s] = val[s];

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (auto &e : bridgeAdj[u])
        {
            int v = e.F;
            if (!visited[v])
            {
                d[v] = d[u] | e.S | val[v];
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> a >> b;

    Tarjan(1, -1);

    FOR(i, 1, n)
    {
        int u = ccId[i];
        for (auto &e : adj[i])
        {
            int v = ccId[e.F], w = e.S;

            if (u == v) val[u] |= w;
            else if (!visited[v])
            {
                bridgeAdj[u].push_back({v, w});
                visited[v] = true;
            }
        }

        for (auto &e : adj[i]) visited[ccId[e.F]] = false;
    }

    BFS(ccId[a]);
    cout << (d[ccId[b]] ? "YES" : "NO");

    return 0;
}