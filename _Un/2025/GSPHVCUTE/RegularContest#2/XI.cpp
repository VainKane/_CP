#include <bits/stdc++.h>

using namespace std;

struct Lake
{
    int x, y, s;
};

#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "hanoi"

int const N = 1009;

int m, n, k; // m = r, n = c
char a[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[N][N];

vector<Lake> lakes;
char ch = '.';

bool cmp(Lake a, Lake b)
{
    return a.s < b.s;
}

int BFS(int x, int y)
{
    queue<pair<int, int>> qu;
    qu.push({x, y});
    visited[x][y] = true;

    int res = 0;
    bool river = false;

    while (!qu.empty())
    {
        int x = qu.front().F;
        int y = qu.front().S;
        qu.pop();

        res++;
        a[x][y] = ch;
        
        if (x == 1 || y == 1) river = true;
        if (x == m || y == n) river = true;

        for (int i = 0; i < 4; i++)
        {
            int xnew = x + dx[i];
            int ynew = y + dy[i];

            if (visited[xnew][ynew]) continue;
            if (a[xnew][ynew] == '#') continue;
            if (x == 0 || y == 0 || x == m + 1 || y == n + 1) continue;
                
            visited[xnew][ynew] = true;
            qu.push({xnew, ynew});
        }
    }

    if (river) res = 0;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) 
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j]) continue;
            if (a[i][j] == '#') continue;
            
            int x = BFS(i, j);
            if (!x) continue;

            lakes.push_back({i, j, x});
        }
    }

    // for (auto lake : lakes)
    // {
    //     cout << lake.x << ' ' << lake.y << ' ' << lake.s << '\n';
    // }

    memset(visited, 0, sizeof visited);
    sort(all(lakes), cmp);

    int r = lakes.size() - k;
    int res = 0;
    ch = '#';

    for (int i = 0; i < r; i++)
    {
        BFS(lakes[i].x, lakes[i].y);
        res += lakes[i].s;
    }

    cout << res << '\n';
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
        }
        cout << '\n';
    }

    return 0;
}