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

int n, m, k, l;

int s[N], d[N], h[N];
int node[N];

vector<int> adj[N], ver[N];
bool f[N], g[N];

void Reset()
{
    FOR(i, 1, n)
    {
        h[i] = f[i] = g[i] = node[i] = 0;
        adj[i].clear();
        ver[i].clear();
    }
}

void BFS()
{
    queue<int> q;
    q.push(1);
    h[1] = 1;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        ver[h[u]].push_back(u);

        for (auto &v : adj[u]) if (!h[v])
        {
            h[v] = h[u] + 1;
            q.push(v);
        }
    }
}


bool Init()
{
    int ma = 0;
    FOR(i, 1, k)
    {
        if (node[h[s[i]]]) return false;
        node[h[s[i]]] = s[i], maxi(ma, h[s[i]]);
    }

    f[1] = 1;

    FOR(i, 1, l) if (h[d[i]] >= ma)
    {
        if (h[d[i]] == ma) g[d[i]] = (d[i] == node[ma]);
        else g[d[i]] = 1;
    }

    return true;
}

bool Check(int u) { return f[u] & g[u]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> l;
        Reset();
     
        FOR(i, 1, k) cin >> s[i];
        FOR(i, 1, l) cin >> d[i];
        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        BFS();
        if (!Init())
        {
            FOR(u, 2, n) cout << 0;
            cout << '\n';
            continue;
        }

        int k = *max_element(h + 1, h + n + 1);
        FOR(i, 1, k) for (auto &u : ver[i]) if (f[u]) for (auto &v : adj[u]) if (h[v] == h[u] + 1)
            f[v] = (!node[i + 1] || v == node[i + 1]);

        FORD(i, k, 1) for (auto &u : ver[i]) if (g[u]) for (auto &v : adj[u]) if (h[v] == h[u] - 1)
            g[v] = (!node[i - 1] || v == node[i - 1]);

        FOR(u, 2, n) cout << Check(u);
        cout << '\n';
    }

    return 0;
}