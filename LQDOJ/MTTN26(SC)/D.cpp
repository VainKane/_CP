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

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Edge
{
    int v, b, p;
};

int const N = 36;

int n, m, k;
vector<int> adj[N];

bool lmao[N];
int mark[N][N];
int b[N][N], p[N][N];

long long res = 0;

void Try(int u, int len, long long cur = 0)
{
    if (len > k)
    {
        maxi(res, cur);
        return;
    }

    for (auto &v : adj[u])
    {
        if (!mark[u][v])
        {
            if (lmao[u] != lmao[v]) cur += b[u][v];
            else cur -= p[u][v];
            mark[u][v]++;
        }
        
        Try(v, len + 1, cur);
        mark[u][v]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    REP(i, m)
    {
        int u, v, bb, pp;
        cin >> u >> v >> bb >> pp;
        u--, v--;
        
        b[u][v] = b[v][u] = bb;
        p[u][v] = p[v][u] = pp;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    REP(mask, MK(n))
    {
        REP(i, n) lmao[i] = BIT(i, mask);
        memset(mark, false, sizeof mark);
        REP(u, n) Try(u, 0);
    }

    cout << res;

    return 0;
}