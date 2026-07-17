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

int const N = 509;
int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};

int n, k, m;
int xs, ys, xt, yt;

bool visited[N][N];
int d[N][N];

bool Inside(int x, int y)
{
    return  x >= 1 && x <= n &&
            y >= 1 && y <= n;
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push({xs, ys});
    visited[xs][ys] = true;

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (visited[u][v] || !Inside(u, v)) continue;

            visited[u][v] = true;
            d[u][v] = d[x][y] + 1;
            q.push({u, v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> n >> k >> m;
    FOR(i, 1, k)
    {
        int x, y;
        cin >> x >> y;
        visited[x][y] = true;
        cin >> x >> y;
    }

    cin >> xs >> ys;
    cin >> xt >> yt;

    BFS();

    cout << (visited[xt][yt] ? d[xt][yt] : -1);
    
    return 0;
}