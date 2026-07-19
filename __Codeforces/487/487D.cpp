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

int const N = 1e5 + 5;
int const M = 14;
int const BK = 314;
int const GR = N / BK + 5;

int bkId[N], bkT[GR], bkB[GR];

int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};
int dir[256];

int m, n, q;
char a[N][M];

pair<int, int> pos[N][M];
bool visited[N][M];

vector<pair<int, int>> used;

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void DFS(int x, int y, pair<int, int> p)
{
    used.push_back({x, y});
    visited[x][y] = true;
    pos[x][y] = p;

    FOR(i, 1, 3)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        int d = dir[a[u][v]];
        if (u + dx[d] != x || v + dy[d] != y) continue;
        if (visited[u][v] || bkId[u] != bkId[x] || !Inside(u, v)) continue;
        DFS(u, v, p);
    }
}

void Build(int id)
{
    FOR(x, bkT[id], bkB[id]) FOR(y, 1, n) pos[x][y] = {x, y};
    FOR(x, bkT[id], bkB[id]) FOR(y, 1, n) if (!visited[x][y]) if (x == bkT[id] || y == 1 || y == n)
    {
        int i = dir[a[x][y]];
        int u = x + dx[i];
        int v = y + dy[i];

        if (bkId[u] == id && Inside(u, v)) continue;
        DFS(x, y, {u, v});
    }

    for (auto &p : used) visited[p.F][p.S] = false;
    used.clear();
}

void Init()
{
    dir['>'] = 1, dir['<'] = 3;

    FOR(i, 1, m) 
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkT[id]) bkT[id] = i;
        bkB[id] = i;
    }

    FOR(i, 1, bkId[m]) Build(i);
}

pair<int, int> Get(int x, int y)
{
    auto p = pos[x][y];

    FOR(haha, 1, GR) 
    {
        if (!Inside(p.F, p.S)) return p;
        p = pos[p.F][p.S];
    }

    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> q;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();

    while (q--)
    {
        char type, c;
        int x, y;

        cin >> type >> x >> y;
        if (type == 'A')
        {
            auto p = Get(x, y);
            cout << p.F << ' ' << p.S << '\n';
        }
        else
        {
            cin >> c;
            a[x][y] = c;
            Build(bkId[x]);
        }
    }

    return 0;
}