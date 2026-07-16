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

int const N = 5009;
long long const oo = 1e18;

int n, m, c;
vector<int> adj[N];


int low[N], in[N];

int ccId[N];
int ccSz[N];

stack<int> st;
int timer = 0, cc = 0;

int dp[N][N];

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st.push(u);

    for (auto &v : adj[u]) if (v != p)
    {
        if (ccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]); 
        }
    }

    if (low[u] == in[u])
    {
        int v = 0;
        cc++;

        while (v != u)
        {
            v = st.top(); st.pop();
            ccId[v] = cc;
            ccSz[cc]++;
        }
    }
}

void Reset()
{
    FOR(u, 1, n)
    {
        adj[u].clear();
        scc[u] = ccId[u] = in[u] = 0;
    }

    memset(dp, 0, sizeof dp);
    cc = timer = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> c;
        Reset();

        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        FOR(u, 1, n) if (!in[u]) Tarjan(u, -1);

           
    }

    return 0;
}