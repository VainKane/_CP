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
int const M = 18;

int n, m, q;

int a[M];
int c[N][N];

void Dijkstra(int s, int d[])
{
    memset(d, 0x3f, (n + 1) * 4);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        REP(v, n) if (mini(d[v], d[u] + c[u][v])) pq.push({d[v], v});
    }
}

namespace Sub4
{
    int d[N][N];
    int dp[MK(17) + 5][M];
    int dist[M][M];

    bool CheckSub()
    {
        return true;
        // return n <= 500;
    }

    void Process()
    {
        REP(i, n) Dijkstra(i, d[i]);
        REP(s, m)
        {
            REP(mask, MK(m)) memset(dp[mask], 0x3f, sizeof dp[mask]);
            dp[MK(s)][s] = 0;
            
            REP(mask, MK(m))
            {
                REP(i, m) if (BIT(i, mask)) REP(j, m) if (!BIT(j, mask))
                {
                    mini(dp[mask | MK(j)][j], dp[mask][i] + d[a[i]][a[j]]);
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
            REP(s, m) REP(t, m) mini(res, d[u][a[s]] + dist[s][t] + d[a[t]][v]);
            cout << res << ' ';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m >> q;

    REP(i, m) cin >> a[i], a[i]--;
    REP(i, n) REP(j, n) cin >> c[i][j];

    if (Sub4::CheckSub()) return Sub4::Process(), 0;

    return 0;
}