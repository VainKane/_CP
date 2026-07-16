#include <bits/stdc++.h>

using namespace std;

#define name "graph"

int const N = 1e5 + 5;
int const oo = 1e9;

int n, m, k;
vector<int> adj[N];
vector<int> revAdj[N];

vector<int> a;
vector<int> b;

int d1[N];
int dA[N];
int dB[N];

int res = 1e9;

void BFS(vector<int> nodes, int d[], vector<int> adj[])
{
    queue<int> qu;

    for (int i = 1; i <= n; i++) d[i] = oo;
    for (auto x : nodes) qu.push(x);
    for (auto x : nodes) d[x] = 0;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u])
        {
            if (d[v] < oo) continue;
            d[v] = d[u] + 1;
            qu.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= k; i++) 
    {
        int x; cin >> x;
        b.push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        int d; cin >> d;
        while (d--)
        {
            int u; cin >> u;
            adj[i].push_back(u);
            revAdj[u].push_back(i);
        }
    }

    vector<int> one = {1};
    
    BFS(one, d1, adj);
    BFS(a, dA, revAdj);
    BFS(b, dB, revAdj);

    for (int u = 1; u <= n; u++)
    {
        if (d1[u] == oo || dA[u] == oo || dB[u] == oo) continue;
        res = min(res, d1[u] + dA[u] + dB[u]);
    }

    if (res == 1e9) 
    {
        cout << "impossible";
        return 0;
    }
    
    cout << res;

    return 0;   
}