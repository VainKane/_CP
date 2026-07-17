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

int s1, t1, l1;
int s2, t2, l2;

vector<int> adj[N];

int d[N][N];

void BFS(int d[], int s)
{
    queue<int> q;
    q.push(s);

    memset(d, -1, (n + 1) * sizeof(int));
    d[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) if (d[v] == -1)
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

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
        adj[v].push_back(u);
    }

    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;

    FOR(u, 1, n) BFS(d[u], u);

    if (d[s1][t1] > l1 || d[s2][t2] > l2)
    {
        cout << -1;
        return 0;
    }

    int res = d[s1][t1] + d[s2][t2];
  
    FOR(u, 1, n) FOR(v, 1, n) REP(r, 2)
    {
        swap(s1, t1);
        int d1 = d[s1][u] + d[u][v] + d[v][t1];
        int d2 = d[s2][u] + d[u][v] + d[v][t2];
        
        if (d1 <= l1 && d2 <= l2) mini(res, d1 + d2 - d[u][v]);
    }

    cout << m - res;

    return 0;
}