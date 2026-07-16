#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

int const N = 1009;

int m, n;

char a[N][N];
int xs, ys, xe, ye;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int d[N][N];
int cnt[N * N];

bool inSide(int x, int y)
{
    return (x >= 1 && x <= m &&
            y >= 1 && y <= n);
}

void BFS(int x0, int y0, bool count)
{
    memset(d, 0, sizeof d);

    queue<pair<int, int>> q;
    q.push({x0, y0});

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();
    
        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (!inSide(u, v) || d[u][v]) continue;

            d[u][v] = d[x][y] + 1;

            if (a[u][v] > '9' || a[u][v] < '0') continue;
            if (count) cnt[d[u][v]] += a[u][v] - '0';
            q.push({u, v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        if (a[i][j] == 'S') xs = i, ys = j;
        if (a[i][j] == 'E') xe = i, ye = j;
    }

    BFS(xe, ye, true);
    BFS(xs, ys, false);

    int res = 0;
    FOR(i, 1, d[xe][ye]) res += cnt[i];
    cout << res;
    
    return 0;
}