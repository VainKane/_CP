#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

int const N = 3e5 + 5;

int n;
vector<int> adj[N];

int in[N];
int deg[N];

int timer = 0;

void DFS(int u, int p)
{
    in[u] = ++timer;
    for (auto &v : adj[u]) if (v != p) DFS(v, u);
}

bool cmp(int u, int v)
{
    return in[u] < in[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
    
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    DFS(1, -1);

    vector<int> v;
    FOR(u, 1, n) if (deg[u] == 1) v.push_back(u);
    sort(all(v), cmp);

    if (sz(v) & 1) v.push_back(v.back());
    cout << sz(v) / 2 << '\n';
    REP(i, sz(v) / 2) cout << v[i] << ' ' << v[i + sz(v) / 2] << '\n';

    return 0;
}