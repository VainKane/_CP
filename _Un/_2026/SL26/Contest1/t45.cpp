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
char res[N];

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

void BFS()
{
    queue<int> q;
    q.push(1);

    string res = "";

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (d[u] == 0) continue;

        int ch = 'z';
        for (auto &e : adj[u])
        {
            int v = e.F, c = e.S;
            if (d[v] == d[u] - 1) mini(ch, c);
        }

        for (auto &e : adj[u])
        {
            int v = e.F, c = e.S;
            if (d[v] == d[u] - 1 && c == ch) q.push(v);
        }

        cout << d[1] - d[u] << ' ' << (char)ch << '\n';
        // res[d[1] - d[u]] = ch;
    }

    cout << res;
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

    // memset(res, 'z', sizeof res);

    BFSPrepare();
    BFS();

    REP(i, d[1]) cout << res[i];

    return 0;
}