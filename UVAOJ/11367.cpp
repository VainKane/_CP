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
    long long du;
    int u, c;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 1009;
int const oo = 1e9;

int n, m;

int a[N];
vector<pair<int, int>> adj[N];

int d[N][109];
int f, s, t;

void Dijkstra()
{
    priority_queue<State> pq;
    memset(d, 0x3f, sizeof d);

    d[s][0] = 0;
    pq.push({0, s, 0});

    while (!pq.empty())
    {
        int u = pq.top().u;
        int c = pq.top().c;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[u][c]) continue;

        if (c < f && mini(d[u][c + 1], d[u][c] + a[u])) pq.push({d[u][c + 1], u, c + 1});
        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (c >= w && mini(d[v][c - w], d[u][c])) pq.push({d[v][c - w], v, c - w});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int q; cin >> q;
    while (q--)
    {
        cin >> f >> s >> t;
        s++, t++;

        Dijkstra();

        int res = oo;
        FOR(i, 0, f) mini(res, d[t][i]);

        if (res == oo) cout << "impossible\n";
        else cout << res << '\n';
    }

    return 0;
}