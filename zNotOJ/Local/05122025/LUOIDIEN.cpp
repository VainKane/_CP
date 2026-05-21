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
#define name "LUOIDIEN"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1509;
int const M = 20;

int n, m, q;

int a[M];
int c[N][N];

int cRev[N][N];
int dRev[M][N];

int d[M][N];
int dp[MK(17) + 5][M];
int dist[M][M];

bool used[N];

void Dijkstra(int s, int d[], int c[][N])
{
    memset(d, 0x3f, (n + 1) * 4);
    memset(used, false, (n + 1));
    d[s] = 0;

    while (true)
    {
        int u = -1;
        int du = 1e9;

        REP(i, n) if (!used[i] && mini(du, d[i])) u = i;
        if (u == -1) break;
        used[u] = true;
        REP(v, n) mini(d[v], d[u] + c[u][v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q;

    REP(i, m) cin >> a[i], a[i]--;
    REP(i, n) REP(j, n) 
    {
        cin >> c[i][j];
        cRev[j][i] = c[i][j];
    }

    REP(i, m) Dijkstra(a[i], d[i], c);
    REP(i, m) Dijkstra(a[i], dRev[i], cRev);

    REP(s, m)
    {
        REP(mask, MK(m)) memset(dp[mask], 0x3f, sizeof dp[mask]);
        dp[MK(s)][s] = 0;

        REP(mask, MK(m))
        {
            for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp & -tmp);
                for (int haha = mask ^ (MK(m) - 1); haha; haha ^= haha & -haha)
                {
                    int j = __builtin_ctz(haha & -haha);
                    mini(dp[mask | MK(j)][j], dp[mask][i] + d[i][a[j]]);
                }
            }
        }

        REP(j, m) dist[s][j] = dp[MK(m) - 1][j];
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;

        int res = 1e9;
        REP(s, m) REP(t, m) mini(res, dRev[s][u] + dist[s][t] + d[t][v]);
        cout << res << ' ';
    }

    return 0;
}