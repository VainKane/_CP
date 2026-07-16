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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, k, q;
vector<int> adj[N];
pair<int, int> a[N];

namespace Sub2
{
    bool CheckSub()
    {
        return n <= 200 && k <= 200 && q <= 200;
    }

    int h[N], par[N];
    bool visited[N];

    void DFS(int u, int p)
    {
        for (auto &v : adj[u]) if (v != p)
        {
            h[v] = h[u] + 1;
            par[v] = u;
            DFS(v, u);
        }
    }

    bool Check(int u, int v)
    {
        if (h[u] < h[v]) swap(u, v);
        vector<int> nodes;

        while (h[u] > h[v])
        {
            nodes.push_back(u);
            u = par[u];
        }

        while (u != v)
        {
            nodes.push_back(u);
            nodes.push_back(v);
            u = par[u], v = par[v];
        }

        nodes.push_back(u);
        bool ok = false;

        for (auto &node : nodes) visited[node] = true;
        
        FOR(i, 1, k) if (visited[a[i].F] && visited[a[i].S])
        {
            ok = true;
            break;
        }

        for (auto &node : nodes) visited[node] = false;
        return ok;
    }

    void Process()
    {
        DFS(1, -1);

        while (q--)
        {
            int u; cin >> u;
            int res = 0;
            FOR(v, 1, n) res += Check(u, v);
            cout << res << ' ';
        }
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        FOR(u, 1, n) if (sz(adj[u]) > 2) return false;
        return true;
    }

    int in[N];
    int timer = 0;

    int l[N], r[N];
    int res[N];

    void DFS(int u, int p)
    {
        in[u] = ++timer;
        for (auto &v : adj[u]) if (v != p) DFS(v, u);
    }

    void Process()
    {
        FOR(u, 1, n) if (sz(adj[u]) == 1)
        {
            DFS(u, -1);
            break;
        }

        FOR(i, 1, n + 1) r[i] = n + 1;

        FOR(i, 1, k)
        {
            a[i].F = in[a[i].F], a[i].S = in[a[i].S];
            if (a[i].F > a[i].S) swap(a[i].F, a[i].S);

            maxi(l[a[i].S], a[i].F);
            mini(r[a[i].F], a[i].S);
        }

        FOR(i, 1, n) maxi(l[i], l[i - 1]);
        FORD(i, n, 1) mini(r[i], r[i + 1]);

        while (q--)
        {
            int u; cin >> u;
            u = in[u];

            cout << l[u] + n - r[u] + 1 << ' ';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> q;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, k) cin >> a[i].F >> a[i].S;

    if (Sub2::CheckSub()) return Sub2::Process(), 0;
    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}