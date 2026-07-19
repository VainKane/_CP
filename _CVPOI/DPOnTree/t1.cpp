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
int const MOD = 1e9 + 7;

int n, m;
vector<int> adj[N], revAdj[N];
bool visited[N];

int d1[N], dn[N];
int deg[N];

void BFS(int s, int d[])
{
    queue<int> q;
    q.push(s);

    memset(visited, false, sizeof visited);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) if (!visited[v])
        {
            visited[v] = true;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void BFSLOL()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    BFS(1, d1);
    BFS(n, dn);

    FOR(u, 1, n) for (auto &v : adj[u]) if (d1[u] + dn[v] + 1 == d[n]) deg[v]++;

    return 0;
}