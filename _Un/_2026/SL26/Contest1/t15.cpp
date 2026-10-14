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

int const N = 5e4 + 5;

int n, m;
vector<int> adj[N];
int d[N], h[N];

void BFSPrepare()
{
    memset(h, -1, sizeof h);

    queue<int> q;
    FOR(u, 1, n) if (d[u] == -1)
    {
        h[u] = 0;
        q.push(u);
    }

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto &v : adj[u]) if (h[v] == -1)
        {
            h[v] = h[u] + 1;
            q.push(v);
        }
    }
}

void BFS()
{
    queue<int> q;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, n) cin >> d[i];

    BFSPrepare();

    return 0;
}