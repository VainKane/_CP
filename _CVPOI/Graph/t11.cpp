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

struct State
{
    int x, y;
    int du;

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 800;

int m, n;
int a[N][N];
int h[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void Dijkstra()
{
    memset(h, 0x3f, sizeof h);
    priority_queue<State> pq;

    FOR(j, 1, n)
    {
        pq.push({1, j, h[1][j] = a[1][j]});
        pq.push({m, j, h[m][j] = a[m][j]});
    }

    FOR(i, 2, m - 1)
    {
        pq.push({i, 1, h[i][1] = a[i][1]});
        pq.push({i, n, h[i][n] = a[i][n]});
    }

    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int du = pq.top().du;
        pq.pop();

        if (du > h[x][y]) continue;

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (Inside(u, v) && mini(h[u][v], max(h[x][y], a[u][v]))) pq.push({u, v, h[u][v]});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Dijkstra();

    long long res = 0;
    FOR(i, 1, m) FOR(j, 1, n) res += h[i][j] - a[i][j];
    cout << res;

    return 0;
}