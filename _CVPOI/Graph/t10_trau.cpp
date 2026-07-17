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
int const oo = 1e9 + 5;

int n, c;
int s[N], p[N];

vector<int> adj[N];

int h[N];
long long dS[N];
int dP[N];

int in[N], out[N];
int node[N];
int timer = 0;

void DFS(int u, int par)
{
    in[u] = ++timer;
    node[in[u]] = u;

    for (auto &v : adj[u]) if (v != par)
    {
        h[v] = h[u] + 1;
        dS[v] = dS[u] + s[v];
        dP[v] = dP[u] + p[v];

        DFS(v, u);
    }

    out[u] = timer;
}

namespace Sub2
{
    bool CheckSub()
    {
        return true;
    }

    void Solve()
    {
        int res = 0;
        FOR(u, 1, n) FOR(id, in[u], out[u])
        {
            int v = node[id];
            if (dS[v] - dS[u] + s[u] <= c) maxi(res, dP[v] - dP[u] + p[u]);
        }

        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, n) cin >> p[i];
    
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dS[1] = s[1], dP[1] = p[1];
    DFS(1, -1);
   
    if (Sub2::CheckSub()) return Sub2::Solve(), 0;

    return 0;
}