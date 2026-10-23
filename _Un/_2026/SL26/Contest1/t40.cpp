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
int const M = 1e6 + 5;

struct Edge
{
    int u, v, w;
    void Input() { cin >> u >> v >> w; }
    bool operator < (Edge const other) const { return w < other.w; }
};

int n, m;

Edge edges[M];
int dp[N], pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m) edges[i].Input();

    sort(edges + 1, edges + m + 1);

    int j;
    for (int i = 1; i <= m; i = j)
    {
        for (j = i; edges[j].w == edges[i].w; j++)
        {
            int u = edges[j].u, v = edges[j].v;
            pre[u] = dp[u], pre[v] = dp[v];
        }

        for (j = i; edges[j].w == edges[i].w; j++)
        {
            int u = edges[i].u, v = edges[i].v;
            maxi(dp[u], pre[v] + 1);
            maxi(dp[v], pre[u] + 1);
        }
    }

    FOR(u, 1, n) cout << dp[u] << ' ';

    return 0;
}