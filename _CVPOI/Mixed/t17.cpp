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

int const N = 509;
ll const oo = 1e18;

int n, m;
vector<pair<int, int>> adj[N];

ll d[N][N];
int deg[N];

bool mark[N];

void Dijkstra(int s, ll d[])
{
    memset(mark, false, sizeof mark);
    memset(d, 0x3f, (n + 1) * sizeof(ll));
    d[s] = 0;

    REP(haha, n - 1)
    {
        int u = 0;
        ll dist = oo;
        FOR(i, 1, n) if (!mark[i] && mini(dist, d[i])) u = i;

        mark[u] = true;

        for (auto &e : adj[u])
        {
            int v = e.F, w = e.S;
            mini(d[v], d[u] + w);
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

    FOR(u, 1, n) Dijkstra(u, d[u]);

    FOR(s, 1, n)
    {
        memset(deg, 0, sizeof deg);
        FOR(u, 1, n) for (auto &e : adj[u])
        {
            int v = e.F, w = e.S;
            deg[v] += (d[s][u] + w == d[s][v]);
        }

        FOR(u, s + 1, n)
        {
            int res = 0;
            FOR(v, 1, n) if (d[s][v] + d[v][u] == d[s][u]) res += deg[v];
            cout << res << ' ';
        }
    }

    return 0;
}