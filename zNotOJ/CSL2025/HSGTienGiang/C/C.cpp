#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second
#define name "ANT"

int const N = 1e3 + 5;
int const MOD = 1e8 + 7;

int n, m;
int a[N][N];

int d[N][N];
int f[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push({1, 1});

    while (!q.empty())
    {   
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (!a[u][v]) continue;

            if (d[u][v] == -1) 
            {
                d[u][v] = d[x][y] + 1;
                q.push({u, v});
            }
            if (d[u][v] == d[x][y] + 1) Add(f[u][v], f[x][y]);
        }
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) 
    {
        char x;
        FOR(j, 1, m) cin >> x, a[i][j] = x - '0';
    }
   
    memset(d, -1, sizeof d);
    d[1][1] = 0;
    f[1][1] = 1;

    BFS();

    if (d[n][m] == -1) d[n][m] = 0;
    cout << f[n][m] << '\n' << d[n][m];

    return 0;
}
