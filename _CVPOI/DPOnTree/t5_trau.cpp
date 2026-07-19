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

int const N = 109;
int const M = 1e4 + 5;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;
vector<int> adj[N];

vector<int> adjVal[M];
int dp[N][M];

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

void DFS(int u, int p)
{
    vector<int> child;

    for (auto &v : adj[u]) if (v != p)
    {
        child.push_back(v);
        DFS(v, u);
    }

    FOR(x, 1, m)
    {
        dp[u][x] = 1;
        for (auto &v : child)
        {
            int tmp = 0;
            for (auto &y : adjVal[x]) Add(tmp, dp[v][y]);
            dp[u][x] = 1LL * dp[u][x] * tmp % MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(x, 2, m) FOR(y, 2, m) if (GCD(x, y) > 1) adjVal[x].push_back(y);
    DFS(1, -1);

    int res = 0;
    FOR(i, 1, m) Add(res, dp[1][i]);
    cout << res;

    return 0;
}