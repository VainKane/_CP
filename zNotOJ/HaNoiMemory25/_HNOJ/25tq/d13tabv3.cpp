#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1009;

int m, n, d;
int a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> adj[N * N];
vector<int> topo;

int h[N * N];
int inDeg[N * N];

int res = 0;

int GetId(int i, int j)
{
    return (i - 1) * m + j;
}

void BFS()
{
    queue<int> q;
    FOR(u, 1, m * n) if (!inDeg[u]) q.push(u);

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

    memset(a, -0x3f, sizeof a);

    cin >> m >> n >> d;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m) FOR(j, 1, n) REP(dir, 4)
    {
        int u = i + dx[dir];
        int v = j + dy[dir];

        if (a[i][j] < a[u][v]) 
        {
            adj[GetId(i, j)].push_back(GetId(u, v));
            inDeg[GetId(u, v)]++;
        }
    }

    BFS();
    for (auto &u : topo) for (auto &v : adj[u]) maxi(h[v], h[u] + 1);
    cout << *max_element(h + 1, h + m * n + 1) + 1 << '\n';

    return 0;
}