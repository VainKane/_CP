#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

struct Data
{
    int x, y, dr;
};

int const N = 209;

int m, n;
char s[N][N];
bool visited[N][N];
bool pushed[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void BFS()
{
    queue<Data> q;
    q.push({2, 2, -1});

    visited[2][2] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int banned = q.front().dr;
        q.pop();

        REP(dr, 4) if (dr != banned) FOR(i, 1, max(m, n))
        {
            int u = x + dx[dr] * i;
            int v = y + dy[dr] * i;

            if (s[u][v] == '#' || pushed[u][v]) break;
            
            if (s[u + dx[dr]][v + dy[dr]] == '#') 
            {
                q.push({u, v, (dr + 2) % 4});
                pushed[u][v] = true;
            }

            visited[u][v] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> s[i][j];

    BFS();

    int res = 0;
    FOR(i, 1, m) FOR(j, 1, n) res += visited[i][j];
    cout << res;

    return 0;
}