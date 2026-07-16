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
    int u;
    bool used;
    long long du;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];

long long d[N][2];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1][0] = 0;

    priority_queue<State> pq;
    pq.push({1, 0, d[1][0]});

    while (!pq.empty())
    {
        int u = pq.top().u;
        bool used = pq.top().used;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[u][used]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (mini(d[v][used], du + w)) pq.push({v, used, d[v][used]});
            if (!used && mini(d[v][1], du + w / 2)) pq.push({v, 1, d[v][1]});
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

    Dijkstra();
    cout << d[n][1];

    return 0;
}