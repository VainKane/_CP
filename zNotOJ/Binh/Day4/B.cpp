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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1009;

int m, n;

char a[N][N];
int h[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void BFS()
{
    int cur = 0, nxt = 1;

    queue<pair<int, int>> q[2];
    q[cur].push({1, 1});

    h[1][1] = 1;
    int res = 0;

    while (!q[cur].empty())
    {
        int x = q[cur].front().F;
        int y = q[cur].front().S;
        q[cur].pop();

        maxi(res, h[x][y]);
        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (a[u][v] == '*' || h[u][v]) continue;
            
            h[u][v] = h[x][y] + (a[u][v] != a[x][y]);
            
            if (a[u][v] == a[x][y]) q[cur].push({u, v});
            else q[nxt].push({u, v});
        }

        if (q[cur].empty())
        {
            swap(cur, nxt);
            q[nxt] = queue<pair<int, int>> ();
        }
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, '*', sizeof a);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    BFS();

    return 0;
}