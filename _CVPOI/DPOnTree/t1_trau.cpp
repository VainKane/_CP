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

int const N = 36;

int n, m;
vector<int> adj[N];
int id[N];

int dist[N], d[N];
bool visited[N];

pair<int, int> edges[N];

void BFS()
{
    queue<int> q;
    q.push(1);

    visited[1] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) if (!visited[v])
        {
            dist[v] = dist[u] + 1;
            visited[v] = true;
            q.push(u);
        }
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (auto &v : adj[u]) if (!visited[v])
    {
        d[v] = d[u] + 1;
        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> edges[i].F >> edges[i].S;
        adj[edges[i].F].push_back(edges[i].S);
    }

    BFS();
    int res = 0;

    FOR(i, 1, n) id[i] = i;
    do
    {
        FOR(u, 1, n) adj[u].clear();
        FOR(i, 1, n)
        {
            auto e = edges[id[i]];
            adj[e.F].push_back(e.S);
        }

        memset(visited, false, sizeof visited);
        d[1] = 0;
        
        DFS(1);
        res += dist[n] == d[n];
    } while (next_permutation(edges + 1, edges + m + 1));

    cout << res;

    return 0;
}