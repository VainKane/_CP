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
ll const oo = 1e18 + 9;

struct Edge { int v, w, id; };

int n, m, s, t, delta;

vector<Edge> adj[N];
ll d[N], res[N];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    memset(res, 0x3f, sizeof res);
    d[s] = res[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        ll du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.v;
            mini(res[v], d[u] + e.w + e.id * (u != s));
            if (mini(d[v], d[u] + e.w + (delta + (u != s)) * e.id)) pq.push({d[v], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t >> delta;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, i});
    }

    Dijkstra(s);
    cout << (res[t] < oo ? res[t] : -1);

    return 0;
}