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

int const N = 5e4 + 5;
int const K = 509;

int n, k;
vector<int> adj[N];

int dp[N][K];
long long res = 0;

void DFS(int u, int p)
{
    dp[u][0] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        REP(i, k) res += 1LL * dp[u][k - i - 1] * dp[v][i];
        FOR(i, 1, k) dp[u][i] += dp[v][i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);
    cout << res;

    return 0;
}