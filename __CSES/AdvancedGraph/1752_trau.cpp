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

int const N = 2e5 + 5;

int n, d;
vector<int> adj[N];

int h[N];

struct cmp
{
    bool operator () (int u, int v) const
    {
        return h[u] < h[v];
    }
};

multiset<int, cmp> dp[N];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFS(v, u);
        dp[u].insert(all(dp[v]));
        dp[v].clear();
    }

    while (true)
    {
        if (sz(dp[u]) < 2) break;

        auto it = dp[u].begin();
        it++;

        if (h[*it] + h[*dp[u].begin()] - 2 * h[u] >= d) break;
        dp[u].erase(dp[u].begin());
    }

    if (dp[u].empty() || h[*dp[u].begin()] - h[u] >= d) dp[u].insert(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    cout << sz(dp[1]) << '\n';
    for (auto &u : dp[1]) cout << u << ' ';

    return 0;
}