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

int n, m;
vector<int> adj[N], revAdj[N];

int d[N], dp[N];

void BFSPrepare()
{
    memset(d, -1, (n + 1) * sizeof(int));
    d[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto &v : adj[u]) if (d[v] == -1)
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void BFS()
{
    memset(dp, 0x3f, sizeof dp);
    dp[n] = 0;

    queue<int> q;
    q.push(n);
    
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto &v : revAdj[u]) if (mini(dp[v], max(d[v], dp[u] + 1))) q.push(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        u++, v++;

        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    BFSPrepare();
    BFS();

    FOR(u, 1, n - 1) cout << dp[u] << ' ';

    return 0;
}