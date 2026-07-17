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

struct Edge
{
    int u, v, w;

    bool operator < (Edge const other) const
    {
        return w < other.w;
    }
};

int const N = 1e6 + 5;
int const MOD = 1e9 + 7;

int n, m;
Edge edges[N];

int dp[N][2];
int f[N];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    sort(edges + 1, edges + m + 1);

    int pre = N;
    for (int l = 1; l <= m;)
    {
        int r;
        for (r = l; edges[r].w == edges[l].w; r++)
        {
            Add(dp[r][1], f[edges[r].u] + 1);
            Add(dp[r][0], f[edges[r].v] + 1);
        }

        FOR(i, pre, l - 1) f[edges[i].u] = f[edges[i].v] = 0;
        
        if (edges[r].w == edges[l].w + 1) for (r = l; edges[r].w == edges[l].w; r++)
        {
            Add(f[edges[r].u], dp[r][0]);
            Add(f[edges[r].v], dp[r][1]);
        }

        pre = l;
        l = r;
    }

    int res = 0;
    FOR(i, 1, m) 
    {
        Add(res, dp[i][0]);
        Add(res, dp[i][1]);
    }

    cout << (res - m + MOD) % MOD;

    return 0;
}