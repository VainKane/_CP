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

int const N = 3e5 + 5;

struct Data
{
    int u, v, id, c;

    bool operator < (Data const other) const
    {
        if (id != other.id) return id < other.id;
        return c < other.c;
    }

    bool operator == (Data const other) const { return id == other.id && c == other.c; }
};

int n, m;

vector<pair<int, char>> adj[N];
int d[N];

int id[N];
bool visited[N];
bool used[N];

ii trace[N];

void BFS()
{
    memset(d, -1, sizeof d);
    d[1] = 0;
    visited[0] = 1;

    queue<int> q;
    q.push(1);

    vector<Data> nodes;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        if (!visited[d[u]])
        {
            sort(all(nodes));

            int j = 0;
            for (int i = 0; i < sz(nodes); i = j) for (j = i; j < sz(nodes) && nodes[j] == nodes[i]; j++)
            {
                int &v = nodes[j].v;
                if (used[v]) continue;

                id[v] = i, trace[v] = {nodes[j].u, nodes[j].c};
                used[v] = true;
            }

            nodes.clear();
        }

        visited[d[u]] = true;

        for (auto &e : adj[u])
        {
            int v = e.F, c = e.S;
            if (d[v] != -1 && visited[d[v]]) continue;
            nodes.push_back({u, v, id[u], c});

            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
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
        char c;

        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    BFS();
    
    string res = "";
    int u = n;
    
    while (u != 1) res += trace[u].S, u = trace[u].F;
    reverse(all(res));
    cout << res;

    return 0;
}