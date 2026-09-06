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

struct DSU
{
    vector<int> par, sz;
    int n;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
    
        MakeSet();
    }

    int Find(int v) { return par[v] == v ? v : par[v] = Find(par[v]); }

    bool Union(int u, int v, bool sw = true)
    {
        u = Find(u), v = Find(v);
        if (u == v) return false;

        if (sw && sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;

        return true;
    }
};

int n, m, k;

int a[N];
vector<int> adj[N];

vector<int> nodes[N];
DSU dsu1, dsu2;

bool visited[N];
map<int, int> mp[N];
int cnt[N];

bool cmp(int u, int v) { return a[u] < a[v]; }

bool Solve()
{
    memset(visited, false, (n + 1) * sizeof(bool));
    queue<int> q;

    FOR(i, 1, k) if (cnt[i] == 1) q.push(i);
    FOR(u, 1, n) for (auto &v : adj[u])
    {
        mp[u][a[v]] = v;
        if (a[u] == a[v] && dsu1.Union(u, v) && --cnt[a[u]] == 1) q.push(a[u]);
    }

    while (!q.empty())
    {
        int c = q.front(); q.pop();

        for (auto &u : nodes[c])
        {
            visited[u] = true;
            
            FOR(i, 1, sz(adj[u]) - 1)
            {
                int x = adj[u][i - 1], y = adj[u][i];
                if (a[x] == a[y] && dsu1.Union(x, y) && --cnt[a[x]] == 1) q.push(a[x]);
            }

            for (auto &v : adj[u]) if (visited[v] && dsu2.Find(u) != dsu2.Find(v))
            {
                int x = dsu2.Find(u), y = dsu2.Find(v);
                if (sz(mp[x]) < sz(mp[y])) swap(mp[x], mp[y]);

                for (auto &p : mp[y])
                {
                    int &z = mp[x][p.F];
                    if (z && dsu1.Union(z, p.S) && --cnt[p.F] == 1) q.push(p.F);
                    z = p.S;
                }
                
                mp[y].clear();
                dsu2.Union(x, y, false);
            }
        }
    }

    return *max_element(cnt + 1, cnt + k + 1) == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;

        FOR(u, 1, n) adj[u].clear(), mp[u].clear();

        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dsu1 = dsu2 = DSU(n);

        FOR(i, 1, k) nodes[i].clear();
        FOR(u, 1, n)
        {
            nodes[a[u]].push_back(u);
            sort(all(adj[u]), cmp);
        }

        FOR(i, 1, k) cnt[i] = sz(nodes[i]);

        cout << (Solve() ? "YES\n" : "NO\n");
    }

    return 0;
}