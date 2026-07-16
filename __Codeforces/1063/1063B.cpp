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
};

int const N = 2009;
int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};

int m, n;
int r, c, x, y;

char a[N][N];
int d[N][N];

void BFS(int xs, int ys)
{
    memset(d, 0x3f, sizeof d);
    d[xs][ys] = 0;

    deque<State> dq;
    dq.push_front({xs, ys, d[xs][ys]});

    while (!dq.empty())
    {
        int x = dq.front().x;
        int y = dq.front().y;
        int du = dq.front().du;
        dq.pop_front();

        if (du > d[x][y]) continue;

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            bool w = i == 3;

            if (a[u][v] != '*' && mini(d[u][v], d[x][y] + w))
            {
                if (w) dq.push_back({u, v, d[u][v]});
                else dq.push_front({u, v, d[u][v]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    cin >> r >> c >> x >> y;

    memset(a, '*', sizeof a);
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    BFS(r, c);

    int res = 0;
    FOR(i, 1, m) FOR(j, 1, n)
        res += d[i][j] <= x && j - c + d[i][j] <= y;

    cout << res;

    return 0;
}