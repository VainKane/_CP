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
int const K = 109;

int n, m, k, s;

int a[N];
vector<int> adj[N];
int d[K][N];

void BFS(int c, int d[])
{
    queue<int> q;

    FOR(i, 1, n)
    {
        if (a[i] == c)
        {
            q.push(i);
            d[i] = 1;
        }
        else d[i] = 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) if (!d[v])
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    FOR(i, 1, n) d[i]--;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> s;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, k) BFS(i, d[i]);

    FOR(u, 1, n)
    {
        vector<int> v;
        FOR(i, 1, k) v.push_back(d[i][u]);
        sort(all(v));

        int res = 0;
        REP(i, s) res += v[i];
        cout << res << ' ';
    }

    return 0;
}