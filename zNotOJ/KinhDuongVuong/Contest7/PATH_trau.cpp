#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Data
{
    long long du;
    int x, y;

    bool operator < (Data const other) const
    {
        return du < other.du;
    } 
};

int const M = 10;
int const N = 5009;

int m, n;
int a[M][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

long long d[M][N];

bool Inside(int x, int y)
{
    return x >= 1 && x <= m 
        && y >= 1 && y <= n;
}

void Dijkstra(int xs, int ys)
{
    priority_queue<Data> pq;
    pq.push({a[xs][ys], xs, ys});

    memset(d, 0x3f, sizeof d);
    d[xs][ys] = a[xs][ys];

    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        long long du = pq.top().du;
        pq.pop();

        if (du > d[x][y]) continue;

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (!Inside(u, v)) continue;
            if (mini(d[u][v], d[x][y] + a[u][v])) pq.push({d[u][v], u, v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    int q; cin >> q;
    while (q--)
    {
        int xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;
        
        Dijkstra(xs, ys);
        cout << d[xt][yt] << '\n';
    }

    return 0;
}