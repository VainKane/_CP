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
    int u, k, len;
    bool dir;
    long long du;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 1e5 + 5;
long long const oo = 1e18;

int n, m, a, b;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> revAdj[N];

long long d[N][5][5][2];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1][0][0][0] = 0;

    priority_queue<State> pq;
    #define PS(v, k, len, dir) pq.push({(v), (k), (len), (dir), (d[v][k][len][dir])})

    PS(1, 0, 0, 0);

    while (!pq.empty())
    {
        int u = pq.top().u;
        int k = pq.top().k;
        int len = pq.top().len;
        bool dir = pq.top().dir;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[u][k][len][dir]) continue;

        if (dir == 0) 
        {
            for (auto &e : adj[u])
            {
                int v = e.F;
                int w = e.S;

                if (mini(d[v][k][len][dir], du + w)) PS(v, k, len, dir);
                if (k < a && mini(d[v][k + 1][len][dir], du)) PS(v, k + 1, len, dir);
            }

            if (mini(d[u][0][0][1], du)) PS(u, 0, 0, 1);
        }

        else for (auto &e : revAdj[u])
        {
            int v = e.F;
            int w = e.S;
            int nLen = min(b, len + 1);

            if (mini(d[v][k][nLen][dir], du + w)) PS(v, k, nLen, dir);
            if (k < b && mini(d[v][k + 1][nLen][dir], du + 2 * w)) PS(v, k + 1, nLen, dir);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> a >> b;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        revAdj[v].push_back({u, w});
    }

    Dijkstra();
    FOR(u, 2, n)
    {
        long long res = oo;
        FOR(len, 0, b) mini(res, d[u][len][len][1]);
        if (res == oo) res = -1;
        cout << res << ' ';
    }

    return 0;
}