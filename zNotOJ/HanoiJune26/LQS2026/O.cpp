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

int const N = 2009;

int n, k;

int a[N];
vector<int> adj[N];

ll dp[N][N];
int sz[N];

void DFS(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);

        FORD(k1, sz[u], 0) FOR(k2, 0, min(sz[v], k - k1))
            maxi(dp[u][k1 + k2], dp[u][k1] + dp[v][k2] + 1LL * k1 * k2 * a[u]);

        sz[u] += sz[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(p + 1);
        adj[p + 1].push_back(i);
    }

    DFS(1, -1);
    cout << dp[1][k];

    return 0;
}