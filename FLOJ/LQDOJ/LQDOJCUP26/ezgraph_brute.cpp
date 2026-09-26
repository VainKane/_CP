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
#define name "ezgraph"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2009;

int m, n;
char a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int id[N][N];
int sz[N * N];
int cc = 0;

bool Inside(int x, int y) { return 1 <= x && x <= m && 1 <= y && y <= n; }

bool DFS(int x, int y, int xPar, int yPar)
{
    id[x][y] = cc;
    sz[cc]++;

    REP(i, 4)
    {
        int u = x + dx[i], v = y + dy[i];

        if (!Inside(u, v) || a[u][v] == '.') continue;
        if (u == xPar && v == yPar) continue;

        if (id[u][v] == cc) return true;
        if (!id[u][v] && DFS(u, v, x, y)) return true;
    }

    return false;
}

bool Check()
{
    FOR(i, 1, m) memset(id[i], 0, (n + 1) * sizeof(int));
    cc = 0;

    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] == '#' && !id[i][j])
    {
        sz[++cc] = 0;
        if (DFS(i, j, -1, -1)) return true;
    }

    return false;
}

ll C2(int x) { return 1LL * x * (x - 1) / 2; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    ll res = 0;
    int cnt = 0;

    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] == '.')
    {
        a[i][j] = '#';

        if (!Check())
        {
            FOR(idx, 1, cc) res += C2(sz[idx]);
            cnt++;
        }

        a[i][j] = '.';
    }

    cout << cnt << ' ' << res;

    return 0;
}