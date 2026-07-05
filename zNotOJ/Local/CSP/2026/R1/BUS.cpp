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
#define name "BUS"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e6 + 5;

struct Edge
{
    int u, v;
    void Input() { cin >> u >> v; }
    int Other(int node) { return node ^ u ^ v; }
};

int n, m, q;

vector<int> adj[N];
Edge e[N];

int d[N], deg[N];
bool used[N], del[N];
int res;

void BFS()
{
    queue<int> q;
    q.push(1);

    d[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &id : adj[u])
        {
            int v = e[id].Other(u);
            
            if (d[v]) used[id] |= d[u] + 1 == d[v];
            else
            {
                d[v] = d[u] + 1;
                used[id] = 1;
                q.push(v);
            }
        }
    }

    FOR(u, 1, n) d[u]--;
}

void Update(int id)
{
    if (!used[id]) return;
    used[id] = 0;

    int s1 = e[id].u, s2 = e[id].v;
    if (d[s1] > d[s2]) swap(s1, s2);

    queue<int> q;
    if (!--deg[s2]) q.push(s2), res--;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (auto &id : adj[u]) if (used[id])
        {
            int v = e[id].Other(u);
            if (!--deg[v]) q.push(v), res--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> q;
    FOR(i, 1, m)
    {
        e[i].Input();
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }

    BFS();
    FOR(u, 1, n) for (auto &id : adj[u]) if (used[id])
    {
        int v = e[id].Other(u);
        deg[v] += d[v] == d[u] + 1;
    }

    res = n - 1;
    while (q--)
    {
        int id; cin >> id;
        Update(id);
        cout << res << '\n';
    }

    return 0;
}