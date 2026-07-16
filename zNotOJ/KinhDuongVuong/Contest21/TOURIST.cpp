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

int const N = 105;
int const K = 35;
int const MOD = 1e9 + 7;

int m, n, k;
bool visited[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

pair<int, int> p[K];
int res = 0;

int Dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.F - b.F) + abs(a.S - b.S);
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

bool Check()
{
    FOR(i, 1, k + 1) if (!visited[p[i].F][p[i].S]) return false;
    return true;
}

void DFS(int x, int y)
{
    visited[x][y] = true;
    REP(i, 4)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        if (u == 1 && v == 1) res += Check();
        if (!Inside(u, v) || visited[u][v]) continue;

        DFS(u, v);
    }
    visited[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;

    FOR(i, 1, k) cin >> p[i].F >> p[i].S;
    p[k + 1] = {m, n};

    DFS(1, 1);
    cout << res;

    return 0;
}
