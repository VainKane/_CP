#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "adventure"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2009;
int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};
char const dir[] = {'^', '>', 'v', '<'};

struct State
{
    int x, y;
    int du;
};

int m, n;
int xs, ys, xt, yt;

char a[N][N];

int d[N][N];
int par[N][N];

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void BFS()
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
            bool w = a[x][y] != dir[i];

            if (Inside(u, v) && mini(d[u][v], d[x][y] + w))
            {
                par[u][v] = i;
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

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        cin >> a[i][j];
        if (a[i][j] == 'o') 
        {
            xs = i;
            ys = j;
        }
        if (a[i][j] == 'x')
        {
            xt = i;
            yt = j;
        }
    }

    BFS();
    cout << d[xt][yt] - 1 << '\n';

    while (true)
    {
        int k = (par[xt][yt] + 2) % 4;
        int u = xt + dx[k];
        int v = yt + dy[k];

        if (u == xs && v == ys) break;

        a[u][v] = dir[par[xt][yt]];  
        xt = u;
        yt = v;
    }

    FOR(i, 1, m) 
    {
        FOR(j, 1, n) cout << a[i][j];
        cout << '\n';
    }

    return 0;
}