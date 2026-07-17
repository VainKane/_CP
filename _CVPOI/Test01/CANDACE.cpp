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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct State
{
    int u, cnt;
    long long du;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 2e3 + 5;
long long const oo = 1e18;

int n, m, a, b;
vector<pair<int, int>> adj[N];

bool mark[N];
long long d[N][N];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1][0] = 0;

    priority_queue<State> pq;
    pq.push({1, 0, d[1][0]});

    while (!pq.empty())
    {
        int u = pq.top().u;
        int cnt = pq.top().cnt;
        long long du = pq.top().du;
        int t = du % (a + b);
        pq.pop();

        if (u == n)
        {
            cout << du;
            exit(0);
        }

        if (du > d[u][cnt]) continue;
        if (!mark[u] && mini(d[u][cnt + 1], du + (a + b) - t)) pq.push({u, cnt + 1, d[u][cnt + 1]});

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (t + w > a) continue;
            if (mini(d[v][cnt], du + w)) pq.push({v, cnt, d[v][cnt]});
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
    }

    FOR(i, 1, n) cin >> mark[i];
    cin >> a >> b;

    Dijkstra();
    cout << -1;

    return 0;
}