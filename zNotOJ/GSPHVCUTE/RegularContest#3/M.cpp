#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second
#define name "unblock"

int const N = 1005;

int m, n;
char a[N][N];
int val[N][N];

int id[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

pair<int, int> root;

void Init()
{
    int cnt = 0;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        if (a[i][j] == 'H') id[i][j] = id[i][j + 1] = ++cnt;
        if (a[i][j] == 'V') id[i][j] = id[i + 1][j] = ++cnt;
        if (a[i][j] == 'O') root = {i, j};
    }
}

long long DFS(int x, int y, int px, int py)
{
    long long res = val[x][y];

    REP(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        int nx2 = nx + dx[i];
        int ny2 = ny + dy[i];

        if (id[nx][ny] != id[nx2][ny2] || !id[nx2][ny2] || (nx2 == px && ny2 == py)) continue;

        swap(id[x][y], id[nx][ny]);
        res += max(DFS(nx2, ny2, x, y), 0ll);
        swap(id[x][y], id[nx][ny]);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, m) FOR(j, 1, n) cin >> val[i][j];

    Init();
    cout << DFS(root.F, root.S, -1, -1);

    return 0;
}