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

int const N = 1e5 + 5;

int n, m;

int a[N];
vector<int> adj[N];
int in[N], out[N];

int node[N];
int timer = 0;

int cnt[N];

void DFS(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    for (auto &v : adj[u]) if (v != p) DFS(v, u);
    out[u] = timer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    FOR(i, 1, m)
    {
        int v, k;
        cin >> v >> k;

        int res = 0;
        
        FOR(i, in[v], out[v]) cnt[a[node[i]]]++;
        FOR(i, in[v], out[v])
        {
            int &x = cnt[a[node[i]]];
            res += x >= k;
            x = 0;
        }

        cout << res << '\n';
    }

    return 0;
}