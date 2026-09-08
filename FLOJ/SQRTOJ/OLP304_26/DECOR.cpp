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
#define name "DECOR"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 14;
int const M = 6767;

int n;
int d[N][N];

bool visited[M];
int dist[N][M];

vector<int> adj[M];

bool Avail(int u, int v)
{
    FOR(k, 1, n) if (k != u && k != v && d[u][k] + d[k][v] == d[u][v]) return true;
    return false;
}

void NoSolution()
{
    cout << "-1 -1\n";
    exit(0);
}

void BFS(int s, int dist[])
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
            dist[v] = dist[u] + 1;
            visited[v] = true;
            q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> d[i][j];

    FOR(i, 1, n) FOR(j, 1, n) if (i != j)
    {
        assert(d[i][j] == d[j][i]);
        if (d[i][j] == 0) NoSolution();
        FOR(k, 1, n) if (k != i && k != j && d[i][k] + d[k][j] < d[i][j])
            NoSolution();
    }

    vector<pair<int, int>> edges;
    int cnt = 0;

    FOR(i, 1, n) FOR(j, i + 1, n) if (!Avail(i, j))
    {
        int pre = i;
        FOR(haha, 1, d[i][j] - 1)
        {
            edges.push_back({pre, n + ++cnt});
            pre = n + cnt;
        }

        edges.push_back({j, pre});
    }

    cout << cnt << ' ' << sz(edges) << '\n';
    for (auto &e : edges) 
    {
        if (e.F > e.S) swap(e.F, e.S);
        cout << e.F << ' ' << e.S << '\n';
    }

    for (auto &e : edges) 
    {
        adj[e.F].push_back(e.S);
        adj[e.S].push_back(e.F);
    }

    FOR(u, 1, n) BFS(u, dist[u]);
    FOR(i, 1, n) FOR(j, 1, n) assert(d[i][j] == dist[i][j]);
    assert(cnt <= 400);

    return 0;
}