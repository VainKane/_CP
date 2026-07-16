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
    int x, y, dir;
    int du;
};

int const N = 1009;
int const oo = 1e9;
int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};

int m, n;
char a[N][N];

int d[N][N][4];

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void BFS()
{
    memset(d, 0x3f, sizeof d);
    d[1][1][1] = 0;

    deque<State> dq;
    dq.push_front({1, 1, 1, d[1][1][1]});

    while (!dq.empty())
    {
        int x = dq.front().x;
        int y = dq.front().y;
        int dir = dq.front().dir;
        int du = dq.front().du;
        dq.pop_front();

        if (du > d[x][y][dir]) continue;

        int u = x + dx[dir];
        int v = y + dy[dir];

        if (Inside(u, v) && mini(d[u][v][dir], du)) dq.push_front({u, v, dir, du});

        if (a[x][y] == '#') REP(i, 4) if (mini(d[x][y][i], du + 1)) 
            dq.push_back({x, y, i, du + 1});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    BFS();
    cout << (d[m][n][1] < oo ? d[m][n][1] : -1);

    return 0;
}