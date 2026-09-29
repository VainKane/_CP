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

int n, m;
vector<int> adj[N], revAdj[N];

int h[N];
bool mark[N];
int deg[N];

void DFS(int u)
{
    for (auto &v : revAdj[u])
    {
        h[v] = h[u] + 1;
        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
        deg[v]++;
    }

    FOR(u, 1, n) if (!sz(adj[u])) DFS(u);

    priority_queue<ii> pq;
    FOR(u, 1, n) if (!sz(revAdj[u])) pq.push({h[u], u});

    int res = 0;
    while (!pq.empty())
    {
        vector<int> nodes;
        REP(haha, m) if (!pq.empty())
        {
            int u = pq.top().S; pq.pop();
            for (auto &v : adj[u]) if (!mark[v] && !--deg[v]) nodes.push_back(v), mark[v] = true;
        }

        for (auto &u : nodes) pq.push({h[u], u});
        res++;
    }

    cout << res;

    return 0;
}