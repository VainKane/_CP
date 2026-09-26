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
ll C2(int x) { return 1LL * x * (x - 1) / 2; }

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

bool Check(vector<int> &v)
{
    REP(i, sz(v)) FOR(j, i + 1, sz(v) - 1) if (v[i] == v[j]) return false;
    return true;
}

void PrintZero()
{
    cout << "0 0";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    ll sum = 0;
    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] == '#' && !id[i][j])
    {
        cc++;
        if (DFS(i, j, -1, -1)) PrintZero();
        sum += C2(sz[cc]);
    }

    ll res = 0;
    int cnt = 0;

    FOR(x, 1, m) FOR(y, 1, n) if (a[x][y] == '.')
    {
        vector<int> haha;
        haha.reserve(5);

        REP(i, 4)
        {
            int u = x + dx[i], v = y + dy[i];
            if (Inside(u, v) && id[u][v]) haha.push_back(id[u][v]);
        }

        if (Check(haha))
        {
            ll tmp = sum;
            int huhu = 1;

            for (auto &idx : haha)
            {
                tmp -= C2(sz[idx]);
                huhu += sz[idx];
            }

            res += tmp + C2(huhu);
            cnt++;
        }
    }

    cout << cnt << ' ' << res;

    return 0;
}