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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 3006;

struct Segment
{
    int l, r, x;
    Segment(int _l = 0, int _r = 0, int _x = 0) { l = _l, r = _r, x = _x; }
    bool operator < (Segment const other) const { return r < other.r; }
};

int m, n, h, w;
char a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int id[N][N];
int cc = 0;

void DFS(int x, int y)
{
    id[x][y] = cc;

    REP(i, 4)
    {
        int u = x + dx[i];
        int v = y + dy[i];
        if (!id[u][v] && a[u][v] == 'x') DFS(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> h >> w;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] == 'x' && !id[i][j]) cc++, DFS(i, j);

    int res = 0;
    FOR(i, 1, m - h + 1) FOR(j, 1, n - w + 1)
    {
        vector<int> v;
        FOR(x, i, i + h - 1) FOR(y, j, j + w - 1) if (a[x][y] == 'x') v.push_back(id[x][y]);

        sort(all(v));
        v.erase(unique(all(v)), v.end());

        maxi(res, sz(v));
    }

    cout << res;

    return 0;
}