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

int const N = 1e5 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

void Add(int &x, int const &y, int const &MOD)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    static Hash I()
    {
        Hash res;
        REP(k, NMOD) res.x[k] = 1;
        return res;
    }

    Hash operator + (Hash const other) const
    {
        Hash res;
        REP(k, NMOD) res.x[k] = (x[k] + other.x[k]) % MODS[k];
        return res;
    }

    Hash operator * (Hash const other) const
    {
        Hash res;

        REP(k, NMOD)
        {
            int a = x[k];
            int b = other.x[k];

            while (b)
            {
                if (b & 1) Add(res.x[k], a, MODS[k]);
                b >>= 1;
                Add(a, a, MODS[k]);
            }
        }

        return res;
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

int n, m;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> revAdj[N];

long long d1[N], d2[N];
Hash f[N], g[N];

void Dijkstra(vector<pair<int, int>> adj[], Hash f[], long long d[], int s)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    memset(d, 0x3f, (n + 1) * 8);
    d[s] = 0;
    f[s] = Hash::I();

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

            if (mini(d[v], d[u] + w)) 
            {
                pq.push({d[v], v});
                f[v] = f[u];
            }
            else if (d[v] == d[u] + w) f[v] = f[v] + f[u];
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
        revAdj[v].push_back({u, w});
    }

    Dijkstra(adj, f, d1, 1);
    Dijkstra(revAdj, g, d2, n);

    vector<int> res;
    FOR(u, 1, n) if (d1[u] + d2[u] == d1[n])
    {
        if (f[u] * g[u] == f[n]) res.push_back(u);
    }

    cout << sz(res) << '\n';
    for (auto &v : res) cout << v << ' ';

    return 0;
}