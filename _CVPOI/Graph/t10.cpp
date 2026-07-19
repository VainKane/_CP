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
int const LOG = 18;
int const oo = 1e9 + 4;

int n, c;
int s[N], p[N];
vector<int> adj[N];

int preS[N], preP[N];
int up[N][20];
int upP[N][20];

void DFS(int u, int par)
{
    for (auto &v : adj[u]) if (v != par)
    {
        preS[v] = preS[u] + s[v];
        preP[v] = preP[u] + p[v];
        
        upP[v][0] = preP[v];
        up[v][0] = u;
        
        FOR(i, 1, LOG) 
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
            upP[v][i] = min(upP[v][i - 1], upP[up[v][i - 1]][i - 1]);
        }

        DFS(v, u);
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

    preS[1] = s[1], preP[1] = p[1];
    DFS(1, -1);

    int res = 0;

    FOR(u, 1, n)
    {
        int v = u;
        FORD(i, LOG, 0) if (preS[u] - preS[up[v][i]] <= c)
        {
            maxi(res, preP[u] - upP[v][i]);
            v = up[v][i];
        }

        maxi(res, preP[u] - preP[v]);
    }

    cout << res;

    return 0;
}