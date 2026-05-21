#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "CEDGE"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, m;
vector<int> adj[N];

bool visited[N];

void DFS(int u)
{
    visited[u] = true;
    for (auto &v : adj[u]) if (!visited[v]) DFS(v);
}

bool Check(int u, int v)
{
    FOR(i, 1, n) visited[i] = false;
    visited[u] = visited[v] = true;

    FOR(i, 1, n) if (i != u && i != v)
    {
        DFS(i);
        break;
    }

    FOR(i, 1, n) if (!visited[i]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = 0;
    FOR(u, 1, n) for (auto &v : adj[u]) if (u < v) res += Check(u, v);
    cout << res;

    return 0;
}