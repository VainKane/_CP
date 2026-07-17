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

int const N = 1509;

int n;
int a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> adj[N * N];
int inDeg[N * N];

vector<int> topo;
int h[N * N];

int GetId(int i, int j)
{
    return (i - 1) * n + j;
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, n * n) if (inDeg[u] == 0) q.push(u);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for (auto &v : adj[u]) if (--inDeg[v] == 0) q.push(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    FOR(x, 1, n) FOR(y, 1, n) REP(i, 4)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        if (a[u][v] <= a[x][y]) continue;
        adj[GetId(x, y)].push_back(GetId(u, v));
        inDeg[GetId(u, v)]++;
    }

    BFS();

    for (auto &u : topo) for (auto &v : adj[u]) maxi(h[v], h[u] + 1);
    cout << *max_element(h + 1, h + n * n + 1);

    return 0;
}