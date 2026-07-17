#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "difference"

int const oo = 1e9;
int m, n;

struct Data
{
    int k, d, x, y;

    bool operator < (Data const other) const
    {
        if (k != other.k) return k < other.k;
        if (d != other.d) return d > other.d;
        return x * n + y > other.x * n + other.y;
    }
};

int subtask;

vector<vector<int>> a;
vector<vector<bool>> visited;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool Inside(int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

Data BFS(int xs, int ys, int delta)
{
    FOR(i, 1, m) FOR(j, 1, n) visited[i][j] = false;
    queue<pair<int, int>> q;

    q.push({xs, ys});
    visited[xs][ys] = true;

    int res = 1;
    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (!Inside(u, v) || visited[u][v] || abs(a[u][v] - a[x][y]) != delta) continue;
            
            visited[u][v] = true;
            res++;
            q.push({u, v});
        }
    }

    return Data {res, delta, xs, ys};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> subtask;
    cin >> m >> n;
    
    a.resize(m + 2, vector<int>(n + 2));
    visited.resize(m + 2, vector<bool>(n + 2));
    
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    Data res{1, 0, 1, 1};

    if (subtask == 1)
    {
        cout << m * n << "0 1 1";
        return 0;
    }

    FOR(x, 1, m) FOR(y, 1, n) REP(i, 4)
    {
        int u = x + dx[i];
        int v = y + dy[i];
        int d = abs(a[x][y] - a[u][v]);

        if (Inside(u, v)) res = max(res, BFS(x, y, d));
    }

    cout << res.k << ' ' << res.d << ' ' << res.x << ' ' << res.y;

    return 0;
}