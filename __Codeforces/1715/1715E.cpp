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

long long Ceil(long long a, long long b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    long long x, a, b;

    long long Val()
    {
        return x * a + b;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;
    int id = 0;

    void Reset()
    {
        seg.clear();
        id = 0;
    }

    void Add(int a, long long b)
    {
        while (!seg.empty() && seg.back().Val() >= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({0, a, b});
        else if (seg.back().a != a) seg.push_back({Ceil(b - seg.back().b, seg.back().a - a), a, b});
    }

    long long Get(int x)
    {
        for(; id < sz(seg) && seg[id].x <= x; id++);
        id--;
        return x * seg[id].a + seg[id].b;
    }
} cht;

int const N = 1e5 + 5;
long long const oo = 1e18;

int n, m, k;
vector<pair<int, int>> adj[N];

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
long long d[N];

void Dijkstra()
{
    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(d, 0x3f, sizeof d);
    pq.push({d[1] = 0, 1});

    Dijkstra();

    REP(haha, k)
    {
        cht.Reset();
        FOR(u, 1, n) if (d[u] < oo) cht.Add(-2 * u, d[u] + 1LL * u * u);
        FOR(u, 1, n) if (mini(d[u], cht.Get(u) + 1LL * u * u)) pq.push({d[u], u});
        Dijkstra();
    }

    FOR(u, 1, n) cout << d[u] << ' ';

    return 0;
}