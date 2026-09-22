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

int f[2][K];

void DFS(int u, int p)
{
    bool cur = 1;
    memset(f[cur ^ 1], 0, sizeof f[cur ^ 1]);

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);

        memset(f[cur], 0, sizeof f[cur]);
        FOR(j, 0, k - 1) FOR(z, 0, k - 1)
        {
            maxi(f[u][max(j, z + 1)], f[u][j] + dp[v][z] + 1);
            maxi(f[u][j], f[u][j] + dp[v][z]);
        }
    }

    FOR(i, 1, k) dp[u][i] = max(f[cur][i], dp[u][i - 1]);
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