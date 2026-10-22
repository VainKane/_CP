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

int n, m;

vector<pair<int, char>> adj[N];
int d[N];

void BFSPrepare()
{
    queue<int> q;
    q.push(n);

    memset(d, -1, sizeof d);
    d[n] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (auto &e : adj[u])
        {
            int v = e.F;
            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

namespace Sub1
{
    bool CheckSub()
    {
        FOR(u, 1, n) for (auto &e : adj[u]) if (e.S != 'a') return false;
        return true;
    }

    void Process()
    {
        BFSPrepare();
        cout << string(d[1], 'a');
    }
}

namespace Sub2
{
    bool CheckSub() { return true; }

    vector<pair<int, char>> dagAdj[N];

    bool visited[N];
    string res[N];

    int deg[N];
    vector<int> topo;

    void BFS()
    {
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int u = q.front(); q.pop();

            char mn = 'z';
            for (auto &e : adj[u])
            {
                int v = e.F;
                if (d[v] != d[u] - 1) continue;

                mini(mn, e.S);
            }

            for (auto &e : adj[u])
            {
                int v = e.F;
                char c = e.S;

                if (d[v] != d[u] - 1 || c != mn) continue;
                dagAdj[u].push_back(e);
                deg[v]++;
                
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    void BFSTopo()
    {
        queue<int> q;
        FOR(u, 1, n) if (!deg[u]) q.push(u);

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            topo.push_back(u);

            for (auto &e : dagAdj[u])
            {
                int v = e.F;
                if (!--deg[v]) q.push(v);
            }
        }
    }

    void Process()
    {
        BFSPrepare();
        BFS();
        BFSTopo();

        FOR(u, 2, n) res[u] = 'z' + 1;
        for (auto &u : topo)
        {
            for (auto &e : dagAdj[u])
            {
                int v = e.F;
                char c = e.S;
                mini(res[v], res[u] + c);
            }

            if (u != n) res[u].clear();
        }

        cout << res[n];
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

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub2::CheckSub()) return Sub2::Process(), 0;

    return 0;
}