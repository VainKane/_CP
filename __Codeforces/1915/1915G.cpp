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
    int u, s;

    bool operator < (State const other) const
    {
        return du > other.u;
    }
};

int const N = 1009;

int n, m;

vector<pair<int, int>> adj[N];
int s[N];

long long d[N][N];
vector<int> vals;

void Compress()
{
    vals.clear();

    FOR(i, 1, n) vals.push_back(s[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) s[i] = lower_bound(all(vals), s[i]) - vals.begin() + 1;
}

void Dijkstra()
{
    priority_queue<State> pq;
    pq.push({0, 1, s[1]});

    memset(d, 0x3f, sizeof d);
    d[1][s[1]] = 0;

    while (!pq.empty())
    {
        int u = pq.top().u;
        int curS = pq.top().s;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[u][curS]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;
            int newS = min(curS, s[v]);

            if (mini(d[v][newS], d[u][curS] + 1LL * vals[curS - 1] * w)) pq.push({d[v][newS], v, newS});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;

        FOR(u, 1, n) adj[u].clear();
        FOR(i, 1, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        FOR(i, 1, n) cin >> s[i];

        Compress();
        Dijkstra();

        cout << *min_element(d[n] + 1, d[n] + n + 1) << '\n';
    }

    return 0;
}