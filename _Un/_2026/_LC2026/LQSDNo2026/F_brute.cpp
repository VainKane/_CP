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

int const N = 2e5 + 5;
int const oo = 1e9 + 9;

int n, d;

ii a[N];
vector<int> adj[N];

bool mark[N];
int dp[N];

void DFS(int u, int p)
{
    dp[u] = 0;
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        dp[u] += dp[v];
    }

    if (dp[u] == 0) dp[u] = !mark[u];
}

int Cal()
{
    FOR(u, 1, n) if (!mark[u])
    {
        DFS(u, -1);
        return (dp[u] + 1) / 2;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i].F, a[i].S = i;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(a + 1, a + n + 1);

    int res = n, j = 1;
    FOR(i, 1, n)
    {
        mark[a[i - 1].S] = false;
        for (; j <= n && a[j].F - a[i].F <= d; j++) mark[a[j].S] = true;
        mini(res, Cal());
    }

    cout << res;

    return 0;
}