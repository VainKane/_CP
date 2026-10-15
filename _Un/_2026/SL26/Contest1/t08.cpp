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

struct State
{
    ll du;
    int u, s;
    bool operator < (State const other) const { return du > other.du; }
};


int n, m, p, f, k;
vector<ii> adj[N];

vector<pair<ll, int>> d[N];

void Dijkstra()
{
    priority_queue<State> pq;
    FOR(u, 1, p) pq.push({0, u, u});

    while (!pq.empty())
    {
        int u = pq.top().u;
        int s = pq.top().s;
        ll du = pq.top().du;
        pq.pop();

        bool lol = false;
        for (auto &p : d[u]) if (p.S == s)
        {
            lol = true;
            break;
        }

        if (sz(d[u]) == k || lol || du > f) continue;
        d[u].push_back({du, s});

        for (auto &e : adj[u])
        {
            int v = e.F, w = e.S;
            pq.push({du + w, v, s});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p >> f >> k;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra();

    vector<int> res;
    FOR(u, p + 1, n) if (sz(d[u]) == k && d[u].back().F <= f) res.push_back(u);

    cout << sz(res) << '\n';
    for (auto &u : res) cout << u << '\n';

    return 0;
}