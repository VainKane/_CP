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
ll const oo = 1e18 + 9;

int n;

vector<int> adj[N];
int a[N];

ll dp[N], f[N];

void DFS(int u, int p)
{
    dp[u] = a[u];
    f[u] = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        dp[u] -= dp[v];
        maxi(f[u], max(dp[v], f[v]));
    }

    maxi(dp[u], 0LL);
    for (auto &v : adj[u]) if (v != p) dp[u] += dp[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll res = oo;

    FOR(u, 1, n)
    {
        DFS(u, -1);
        mini(res, max({f[u], 1LL * a[u], (dp[u] + 1) / 2}));
        // cout << f[u] << ' ';
        cout << dp[u] << ' ';
    }

    cout << res;

    return 0;
}