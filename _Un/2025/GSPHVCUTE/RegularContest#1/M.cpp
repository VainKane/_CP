#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second
#define name "skwthr"

int const N = 11;
int const D = 31;
int const KR = 7;

struct Data
{
    int i, x, y;
    int c1, c2, c3, c4;
};

int t;
int r, c, k;
int a, b, d;
pair<int, int> s;
int n;

pair<int, int> cor[5];

int pre[D][N][N];
bool fes[D][N][N];
bool ok[D][N][N];
bool f[D][N][N][KR][KR][KR][KR];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int GetSum(int i, int x, int y, int u, int v)
{
    if (x > u || y > v) return 0;
    return pre[i][u][v] - pre[i][u][y - 1] - pre[i][x - 1][v] + pre[i][x - 1][y - 1];
}

bool Outside(int x, int y)
{
    if (x < 0 || x + a - 1 > r) return true;
    if (y < 0 || y + b - 1 > c) return true;
    return false;
}

bool Solve()
{
    if (!ok[1][s.F][s.S]) return false;
    if (n == 1) return true;

    int cr1 = (cor[1] == s ? 0 : 1);
    int cr2 = (cor[2] == s ? 0 : 1);
    int cr3 = (cor[3] == s ? 0 : 1);
    int cr4 = (cor[4] == s ? 0 : 1);
 
    queue<Data> q;
    q.push(Data {1, s.F, s.S, cr1, cr2, cr3, cr4});
    f[1][s.F][s.S][cr1][cr2][cr3][cr4] = true;

    while (!q.empty())
    {
        int cr[5];

        int i = q.front().i;
        int x = q.front().x;
        int y = q.front().y;
        
        int c1 = q.front().c1;
        int c2 = q.front().c2;
        int c3 = q.front().c3;
        int c4 = q.front().c4;

        q.pop();

        REP(dir, 4) FOR(steps, 0, d)
        {
            int u = x + dx[dir] * steps;
            int v = y + dy[dir] * steps;

            if (Outside(u, v) || !ok[i + 1][u][v]) continue;

            pair<int, int> pos = {u, v};
            int cc1 = (cor[1] == pos ? 0 : c1 + 1);
            int cc2 = (cor[2] == pos ? 0 : c2 + 1);
            int cc3 = (cor[3] == pos ? 0 : c3 + 1);
            int cc4 = (cor[4] == pos ? 0 : c4 + 1);

            if (f[i + 1][u][v][cc1][cc2][cc3][cc4]) continue;
            if (cc1 > k || cc2 > k || cc3 > k || cc4 > k) continue;

            f[i + 1][u][v][cc1][cc2][cc3][cc4] = true;
            q.push(Data {i + 1, u, v, cc1, cc2, cc3, cc4});

            if (i + 1 == n) return true;
        }
    }

    return false;
}

void Init()
{
    cor[1] = {1, 1};
    cor[2] = {1, c - b + 1};
    cor[3] = {r - a + 1, c - b + 1};
    cor[4] = {r - a + 1, 1};

    FOR(i, 1, n) FOR(x, 1, r) FOR(y, 1, c)
        pre[i][x][y] = pre[i][x][y - 1] + pre[i][x - 1][y] - pre[i][x - 1][y - 1] + fes[i][x][y];
    
    FOR(i, 1, n) FOR(x, 1, r) FOR(y, 1, c)
        ok[i][x][y] = !GetSum(i, x, y, x + a - 1, y + b - 1);

    memset(f, false, sizeof f);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> r >> c >> k;
        cin >> a >> b >> s.F >> s.S >> d;
        cin >> n;
        FOR(i, 1, n) FOR(x, 1, r) FOR(y, 1, c) cin >> fes[i][x][y];

        Init();
        cout << Solve();
    }

    return 0;
}