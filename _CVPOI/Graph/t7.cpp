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
    int u, tele, len;
    int du;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 1e4 + 5;
int const oo = 2e9;

int n, m, p, l, k;
vector<pair<int, int>> adj[N];

int d[N][11][11];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1][0][0] = 0;

    priority_queue<State> pq;
    #define PS(v, tele, len) pq.push({v, tele, len, d[v][tele][len]})

    PS(1, 0, 0);

    while (!pq.empty())
    {
        int u = pq.top().u;
        int tele = pq.top().tele;
        int len = pq.top().len;
        int du = pq.top().du;
        pq.pop();

        if (du > d[u][tele][len]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (!len && mini(d[v][tele][len], du + w)) PS(v, tele, len);
            if (len < l && mini(d[v][tele][len + 1], du)) PS(v, tele, len + 1);
        }

        if (tele < k && mini(d[u][tele + 1][0], du + p)) PS(u, tele + 1, 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p >> l >> k;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra();

    int res = oo;
    FOR(tele, 0, k) mini(res, d[n][tele][0]);
    cout << res;

    return 0;
}