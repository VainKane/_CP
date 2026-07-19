#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))
#define F first
#define S second
    
int const N = 1e5 + 5;

int n, m, k;
int a[N], b[N];

vector<int> adj[N];
int d[N][MK(5) + 5];

int mask = 0;

void BFS(int s, int mask)
{
    memset(d, -1, sizeof d);
    queue<pair<int, int>> q;
    q.push({s, mask});
    d[s][mask] = 0;

    while (!q.empty())
    {
        int u = q.front().F;
        int mask = q.front().S;
        q.pop();

        for (auto v : adj[u]) 
        {
            int tmp = mask;
            if (b[v] != -1) tmp |= MK(b[v]);

            if ((a[v] == -1 || BIT(a[v], mask)) & d[v][tmp] == -1)
            {
                d[v][tmp] = d[u][mask] + 1;
                q.push({v, tmp});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, n) 
    {
        cin >> a[i];
        if (a[i] != -1) a[i]--;
    }
    FOR(i, 1, n) 
    {
        cin >> b[i];
        if (b[i] == -1) continue;
        
        b[i]--;
        if (i == 1) mask |= MK(b[i]);
    }
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(1, mask);

    FOR(u, 1, n) 
    {
        int res = 1e9;
        REP(mask, MK(k)) if (d[u][mask] != -1) res = min(res, d[u][mask]);
        if (res == 1e9) res = -1;
        cout << res << ' ';
    }

    return 0;
}