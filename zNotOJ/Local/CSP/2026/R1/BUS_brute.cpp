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

bool del[N];
int d[N], haha[N];

void BFS(int d[])
{
    memset(d, 0, (n + 1) * sizeof(int));

    queue<int> q;
    q.push(1);
    d[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &id : adj[u]) if (!del[id])
        {
            int v = e[id].Other(u);
            if (d[v]) continue;

            d[v] = d[u] + 1;
            q.push(v);
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

    BFS(haha);

    while (q--)
    {
        int id; cin >> id;
        del[id] = 1;
    
        BFS(d);
        
        int res = 0;
        FOR(u, 2, n) res += haha[u] == d[u];
        cout << res << '\n';
    }

    return 0;
}