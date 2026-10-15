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

vector<int> s[N];

int d[N], dist[N];
bitset<N> bs[N];

bool visited[N];

void PrintAll()
{
    FOR(u, 1, n) if (dist[u] != -1) return;
    
    cout << n << '\n';
    FOR(u, 1, n) cout << u << ' ';
    exit(0);
}

void BFS()
{
    queue<int> q;

    memset(d, -1, sizeof d);
    for (auto &u : s[*max_element(dist + 1, dist + n + 1)])
    {
        d[u] = dist[u];
        bs[u][u] = 1;

        visited[u] = 1;
        q.push(u);
    }

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (d[u] == 0) continue;

        for (auto &v : s[d[u] - 1])
        {
            if (visited[v]) continue;
            if (d[v] != -1 && d[v] != d[u] - 1)
            {
                cout << "0";
                exit(0);
            }

            d[v] = d[u] - 1;
            bs[v][v] = 1;

            visited[v] = true;
            q.push(v);
        }

        for (auto &v : adj[u])
        {
            if (d[v] != -1 && d[v] != d[u] - 1) continue;
            bs[v] |= bs[u];

            if (visited[v]) continue;

            visited[v] = true;
            d[v] = d[u] - 1;
            q.push(v);
        }
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

    int cnt = 0;
    FOR(u, 1, n)
    {
        cin >> dist[u];
        if (dist[u] != -1) s[dist[u]].push_back(u), cnt++;
    }

    PrintAll();

    BFS();

    vector<int> res;
    FOR(u, 1, n) if (d[u] == 0 && bs[u].count() == cnt) res.push_back(u);

    cout << sz(res) << '\n';
    for (auto &u : res) cout << u << ' ';

    return 0;
}