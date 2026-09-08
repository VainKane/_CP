#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

int const N = 1e3 + 7;

int m, n;
int a[N][N];

int cnt[N][N];
bool melted[N][N];

vector<pair<int, int>> cur, nxt;
queue<pair<int, int>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS()
{
    while (!q.empty())
    {   
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        melted[x][y] = true;
        a[x][y] = 0;

        REP(i, 4) 
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (u < 1 || u > m || v < 1 || v > n) continue;
            if (melted[u][v]) continue;

            if (a[u][v]) 
            {
                cnt[u][v]++;
                if (cnt[u][v] == 2) nxt.push_back({u, v});
            }
            else
            {
                melted[u][v] = true;
                a[u][v] = 0;

                q.push({u, v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    q.push({1, 1});
    BFS();

    swap(cur, nxt);
    int res = 0;

    while (!cur.empty())
    {
        for (auto p : cur) q.push({p.F, p.S});
        BFS();
        
        cur = nxt;
        nxt.clear();

        res++;
    }

    cout << res;

    return 0;
}