#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

int const N = 1e3 + 5;

int m, n;
int a[N][N];

int cnt[N][N];
bool melted[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    melted[x][y] = true;
    a[x][y] = 0;

    while (!q.empty())
    {   
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        REP(i, 4) 
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (a[u][v]) cnt[u][v]++;
            else if (!melted[u][v]) 
            {
                melted[u][v] = true;
                a[u][v] = 0;

                q.push({u, v});
            }
        }
    }
}

void Init()
{
    FOR(i, 1, m) a[i][0] = a[i][n + 1] = 1;
    FOR(j, 1, n) a[0][j] = a[m + 1][j] = 1;

    BFS(1, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();

    int res = 0;

    while (true)
    {
        vector<pair<int, int>> air;
            
        FOR(x, 1, m) FOR(y, 1, n) if (!melted[x][y] && cnt[x][y] >= 2) air.push_back({x, y});

        if (air.empty()) break;
        for (auto p : air) BFS(p.F, p.S);

        res++;
    }

    cout << res;

    return 0;
}