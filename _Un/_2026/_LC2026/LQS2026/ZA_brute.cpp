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

int n, m, k;

int a[N];
vector<int> adj[N];

vector<int> nodes[N];
bool visited[N], del[N];
bool mark[N];

void Reset()
{
    FOR(u, 1, n) adj[u].clear();
    FOR(i, 1, k) nodes[i].clear();
    memset(del, false, sizeof del);
    memset(mark, false, sizeof mark);
}

bool Check(int c)
{
    if (nodes[c].empty()) return false;

    queue<int> q;
    q.push(nodes[c][0]);

    memset(visited, false, (n + 1) * sizeof(bool));
    visited[nodes[c][0]] = true;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (auto &v : adj[u]) if ((a[v] == c || del[v]) && !visited[v])
        {
            visited[v] = true;
            q.push(v);
        }
    }

    for (auto &u : nodes[c]) if (!visited[u]) return false;
    return true;
}

bool Solve()
{
    FOR(u, 1, n) if (!del[u]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;

        Reset();

        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        FOR(u, 1, n) nodes[a[u]].push_back(u);
        REP(haha, k) FOR(i, 1, k) if (!mark[i] && Check(i))
        {
            for (auto &u : nodes[i]) del[u] = true;
            mark[i] = true;
        }

        cout << (Solve() ? "YES\n" : "NO\n");
    }

    return 0;
}