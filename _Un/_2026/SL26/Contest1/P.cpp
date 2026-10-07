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
int d[N], f[N];

void BFS()
{
    memset(f, 0x3f, sizeof f);

    priority_queue<ii, vector<ii>, greater<ii>> q;
    FOR(u, 1, n) if (d[u] != -1)
    {
        f[u] = d[u];
        q.push({f[u], u});
    }

    while (!q.empty())
    {
        int u = q.top().S;
        int fu = q.top().F;
        q.pop();

        if (fu > f[u]) continue;
        for (auto &v : adj[u]) if (mini(f[v], f[u] - 1)) q.push({f[v], v});
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, n) cin >> d[i];

    BFS();

    vector<int> res;
    FOR(u, 1, n) if (d[u] == -1 && f[u] >= 0) res.push_back(u);

    cout << sz(res) << '\n';
    for (auto &u : res) cout << u << ' ';

    return 0;
}