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
int const MOD = 1e9 + 7;

int n;
vector<int> adj[N];

int f[N];

void DFS(int u, int p)
{
    f[u] = 1;
    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] = 1LL * f[u] * (f[v] + 1) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    FOR(u, 1, n)
    {
        DFS(u, -1);
        cout << f[u] << ' ';
    }

    return 0;
}