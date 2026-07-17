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

struct Node
{
    int i, x, y;
};

int const N = 509;
int const K = 15009;
int const M = 67;
int const oo = 1e9;

int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};

int n, k, m;
int x[K], y[K], r[K], t[K];
int xs, ys, xt, yt;

bool blocked[M][N][N];

bool visited[M][N][N];
int d[M][N][N];

bool Inside(int x, int y)
{
    return  x >= 1 && x <= n &&
            y >= 1 && y <= n;
}

void BFS()
{
    queue<Node> q;
    q.push({0, xs, ys});

    visited[0][xs][ys] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int i = q.front().i;
        q.pop();

        int tmp = (i + 1) % 60;
        if (!visited[tmp][x][y] && !blocked[tmp][x][y])
        {
            d[tmp][x][y] = d[i][x][y] + 1;
            visited[tmp][x][y] = true;
            q.push({tmp, x, y});
        }
        
        REP(dir, 4)
        {
            int u = x + dx[dir];
            int v = y + dy[dir];

            if (!Inside(u, v) || visited[tmp][u][v]) continue;
            if (blocked[tmp][u][v]) continue;
            
            d[tmp][u][v] = d[i][x][y] + 1;
            visited[tmp][u][v] = true;
            q.push({tmp, u, v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> n >> k >> m;
    FOR(i, 1, k) cin >> x[i] >> y[i] >> r[i] >> t[i];
    cin >> xs >> ys;
    cin >> xt >> yt;

    FOR(id, 0, 59) FOR(i, 1, k)
    {
        FOR(u, -t[i], t[i]) FOR(v, -t[i], t[i])
        {
            if (abs(u) + abs(v) > t[i]) continue;
            if (!Inside(x[i] + u, y[i] + v)) continue;
            blocked[id][x[i] + u][y[i] + v] = true;
        }
        if (++t[i] == r[i]) t[i] = 0;
    }

    BFS();

    int res = oo;
    REP(rem, 60) if (visited[rem][xt][yt]) mini(res, d[rem][xt][yt]);
    if (res == oo) res = -1;

    cout << res;

    return 0;
}