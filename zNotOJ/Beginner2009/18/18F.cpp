#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

struct Pos
{
    int x, y, delta;
};

int const N = 509;
int const MOD = 1e9 + 9;

int h, w;
char a[N][N];

Pos E, X;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int d[N][N];
int f[N][N][2];

bool visited[N][N];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void BFS()
{
    queue<Pos> q;
    q.push(E);

    f[E.x][E.y][0] = 1;
    d[E.x][E.y] = 0;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int delta = q.front().delta;
        q.pop();

        int dist = d[x][y] + delta * 2 + 1;

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (a[u][v] == '#') continue;
        
            if (d[u][v] == -1)
            {
                d[u][v] = d[x][y] + 1;
                q.push(Pos{u, v, 0});
            }
            if (d[u][v] == dist) Add(f[u][v][0], f[x][y][delta]);
            if (d[u][v] == dist - 2)
            {
                if (!visited[u][v])
                {
                    q.push(Pos{u, v, 1});
                    visited[u][v] = true;
                }
                Add(f[u][v][1], f[x][y][delta]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, '#', sizeof a);
    memset(d, -1, sizeof d);

    cin >> h >> w;
    FOR(i, 1, h) FOR(j, 1, w)
    {
        cin >> a[i][j];
        if (a[i][j] == 'E') E = {i, j, 0};
        if (a[i][j] == 'X') X = {i, j, 0};
    }

    BFS();
    cout << f[X.x][X.y][1] << '\n';

    return 0;
}