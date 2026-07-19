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

int n, m, k;
vector<int> adj[N];

bool mark[N];
int d1[N], d2[];

void BFS(int d[])
{
    queue<int> q;

    memset(d, -1, sizeof d);

    FOR(i, 1, n) if (mark[i]) 
    {
        q.push(i);
        d[i] = 0;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u])
        {
            if (mark[v])
            {
                if (!d[v]) d[v] = d[u] + 1;
            }
            else if (d[v] == -1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    FOR(i, 1, k)
    {
        int u; cin >> u;
        mark[u] = true;
    }

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS();
    FOR(u, 1, n) cout << d[u] << ' ';

    return 0;
}