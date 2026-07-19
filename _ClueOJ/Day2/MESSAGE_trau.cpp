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
#define name "MESSAGE"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Edge
{
    int v, w, f;
};

struct Data
{
    long long du;
    int f, u;

    bool operator < (Data const other) const
    {
        return du > other.du;
    }
};

int const N = 2e5 + 5;
long long const oo = 1e18;

int n, m, s, t;
vector<Edge> adj[N];

namespace Sub2
{
    Edge par[N];
    int h[N];

    bool CheckSub()
    {
        return m == n - 1;
    }

    void DFS(int u, int p)
    {
        for (auto &e : adj[u])
        {
            int v = e.v;
            if (v == p) continue;

            h[v] = h[u] + 1;
            par[v] = {u, e.w, e.f};

            DFS(v, u);
        }
    }

    long long Cal(int s, int t)
    {
        if (h[s] < h[t]) swap(s, t);
        long long res = 0;

        int pre = par[s].f;
        while (h[s] > h[t])
        {
            res += par[s].w + abs(par[s].f - pre);
            pre = par[s].f;
            s = par[s].v;
        }

        if (s == t) return res;

        int preS = pre;
        int preT = par[t].f;
        while (s != t)
        {
            res += par[s].w + par[t].w + abs(par[s].f - preS) + abs(par[t].f - preT);

            preS = par[s].f;
            preT = par[t].f;

            s = par[s].v;
            t = par[t].v;
        }

        return res + abs(preS - preT);
    }

    void Process()
    {
        DFS(1, -1);
        cout << Cal(s, t);
    }
}

namespace Sub4
{
    long long d[N][25];

    bool CheckSub()
    {
        return true;
    }

    void Dijkstra()
    {
        memset(d, 0x3f, sizeof d);
        priority_queue<Data> pq;

        FOR(i, 1, 20)
        {
            d[s][i] = 0;
            pq.push({0, i, s});
        }

        while (!pq.empty())
        {
            int u = pq.top().u;
            int f = pq.top().f;
            long long du = pq.top().du;
            pq.pop();

            if (du > d[u][f]) continue;

            for (auto &e : adj[u])
            {
                int v = e.v;
                int w = e.w;

                if (mini(d[v][e.f], d[u][f] + w + abs(f - e.f))) pq.push({d[v][e.f], e.f, v});
            }
        }
    }

    void Process()
    {
        Dijkstra();
        cout << *min_element(d[t] + 1, d[t] + 21);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;
    FOR(i, 1, m)
    {
        int u, v, w, f;
        cin >> u >> v >> w >> f;
        adj[u].push_back({v, w, f});
        adj[v].push_back({u, w, f});
    }

    if (Sub2::CheckSub()) return Sub2::Process(), 0;
    if (Sub4::CheckSub()) return Sub4::Process(), 0;

    return 0;
}
