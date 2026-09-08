#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

struct Data
{
    int x, y, dir;
};

int const N = 209;

int m, n;
char a[N][N];
bool visited[N][N][4];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<char, int>> res;
int mirrors = 0;

bool inSide(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= n;
}

void TryPush(queue<Data> &q, int const &u, int const &v, int &dir)
{
    if (inSide(u, v) && !visited[u][v][dir]) 
    {
        visited[u][v][dir] = true;
        q.push({u, v, dir});
    }
}

bool BFS(int xs, int ys, int dir)
{
    memset(visited, false, sizeof visited);
    visited[xs][ys][dir] = true;
    vector<pair<int, int>> pos;

    queue<Data> q;
    q.push({xs, ys, dir});

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();

        if (a[x][y] == '.')
        {
            int u = x + dx[dir];
            int v = y + dy[dir];
            TryPush(q, u, v, dir);
        }
        else if (a[x][y] == '/')
        {
            if (dir & 1) dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
            TryPush(q, x + dx[dir], y + dy[dir], dir);
            pos.push_back({x, y});
        }
        else
        {
            if (dir & 1) dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            TryPush(q, x + dx[dir], y + dy[dir], dir);
            pos.push_back({x, y});
        }
    }

    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    
    return sz(pos) == mirrors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        mirrors += a[i][j] != '.';
    }

    FOR(i, 1, m)
    {
        if (BFS(i, 1, 1)) res.push_back({'W', i});
        if (BFS(i, n, 3)) res.push_back({'E', i});
    }

    FOR(i, 1, n)
    {
        if (BFS(1, i, 2)) res.push_back({'N', i});
        if (BFS(m, i, 0)) res.push_back({'S', i});
    }

    cout << sz(res) << '\n';
    for (auto &p : res) cout << p.F << p.S << ' ';

    return 0;
}