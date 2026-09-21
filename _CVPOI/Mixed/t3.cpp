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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
int const K = 36;

int n, k;

vector<int> adj[N];
int dp[N][K];

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        FORD(i, k, 1) FOR(j, 0, i)
        {
            maxi(dp[u][i], dp[u][j] + dp[v][i - j]);
            if (i - j - 1 >= 0) maxi(dp[u][i], dp[u][j] + dp[v][i - j - 1] + 1);
        }
    }

    FOR(i, 1, k) maxi(dp[u][i], dp[u][i - 1]);
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
    // cout << dp[1][k - 1];
    cout << dp[3][1];

    return 0;
}