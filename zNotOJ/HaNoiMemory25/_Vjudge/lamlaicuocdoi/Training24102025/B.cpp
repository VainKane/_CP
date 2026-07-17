#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2009;
double const oo = 1e18;

int n, m, t;
vector<pair<int, double>> adj[N];

double d[N];

void Dijkstra()
{
    FOR(i, 2, n) d[i] = oo;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().S;
        double du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            double w = e.S;

            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> t;
    FOR(i, 1, m)
    {
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        
        double w = sqrtl(1ll * l * c);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra();
    cout << fixed << setprecision(10) << d[n] / t * d[n];

    return 0;
}