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

int const N = 69;

int n, m, q;
pair<int, int> e[N], p[N];

vector<int> adj[N];
bool visited[N];

void DFS(int u)
{
    visited[u] = true;
    for (auto &v : adj[u]) if (!visited[v]) DFS(v);
}

bool Check()
{
    FOR(i, 1, q)
    {
        memset(visited, false, sizeof visited);
        DFS(p[i].F);
        if (!visited[p[i].S]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    REP(i, m) cin >> e[i].F >> e[i].S;
    FOR(i, 1, q) cin >> p[i].F >> p[i].S;

    REP(mask, MK(m))
    {
        FOR(u, 1, n) adj[u].clear();
        REP(i, m)
        {
            if (BIT(i, mask)) adj[e[i].F].push_back(e[i].S);
            else adj[e[i].S].push_back(e[i].F);
        }

        if (Check())
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}