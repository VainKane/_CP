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

int const N = 3009;

int n, m;
vector<int> adj[N];
vector<int> revAdj[N];

int cnt[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    FOR(u, 1, n) for (auto &v1 : revAdj[u]) for (auto &v2 : adj[u]) cnt[v1][v2]++;

    long long res = 0;
    FOR(u, 1, n) FOR(v, u + 1, n) 
    {
        res += cnt[u][v] * (cnt[u][v] - 1);
        res += cnt[v][u] * (cnt[v][u] - 1);
    }

    cout << res / 2;

    return 0;
}