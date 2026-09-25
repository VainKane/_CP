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

int const N = 2e5 + 5;
ll oo = 1e18 + 9;

struct Edge
{
    int u[2], pos[2];
    int f;

    Edge(int _u = 0, int _v = 0, int _f = 0) { u[0] = _u, u[1] = _v, f = _f; }
    void Input() { cin >> u[0] >> u[1] >> f; }
};

struct State
{
    ll du;
    int id, j;

    bool operator < (State const other) const { return du > other.du; }
};

int n, m;

Edge edges[N];
vector<int> adj[N];

bool cmp(int i, int j) { return edges[i].f < edges[j].f; }

ll d[N][2];
vector<int> delta = {-1, 1};

void Dijkstra(int s)
{
    priority_queue<State> pq;
    memset(d, 0x3f, sizeof d);

    d[m + 1][0] = 0;
    pq.push({d[m + 1][0], m + 1, 0});

    while (!pq.empty())
    {
        auto state = pq.top();
        int id = state.id;
        bool j = state.j;

        int u = edges[id].u[j];
        int i = edges[id].pos[j];

        ll du = state.du;
        pq.pop();

        if (du > d[id][j]) continue;

        if (mini(d[id][j ^ 1], du)) pq.push({d[id][j ^ 1], id, j ^ 1});

        for (auto &de : delta) if (i + de >= 0 && i + de < sz(adj[u]))
        {
            int nxt = adj[u][i + de];
            REP(k, 2) if (edges[nxt].u[k] == u && mini(d[nxt][k], du + abs(edges[nxt].f - edges[id].f)))
                pq.push({d[nxt][k], nxt, k});
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
        edges[i].Input();
        REP(j, 2) adj[edges[i].u[j]].push_back(i);
    }

    edges[m + 1] = {1, 1, 0};
    adj[1].push_back(m + 1);

    FOR(u, 1, n)
    {
        sort(all(adj[u]), cmp);
        REP(i, sz(adj[u]))
        {
            int id = adj[u][i];
            REP(j, 2) if (u == edges[id].u[j]) edges[id].pos[j] = i;
        }
    }

    Dijkstra(1);

    ll res = oo;
    FOR(i, 1, m) REP(j, 2) if (edges[i].u[j] == n) mini(res, d[i][j]);
    cout << res;

    return 0;
}