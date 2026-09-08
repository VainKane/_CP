#include <bits/stdc++.h>

using namespace std;

int const N = 100009;

int n;
vector<int> adj[N];
bool visisted[N];
int par[N];

void Print(int start, int end)
{
    // vector<int> res;

    // res.push_back(start);
    // while (end != start)
    // {
    //     res.push_back(end);
    //     end = par[end];
    // } 
    // res.push_back(start);
     
    // reverse(res.begin(), res.end());

    cout << "YES\n";
    // for (auto val : res) cout << val << ' ';

    exit(0);
}

void DFS(int u, int p)
{
    visisted[u] = true;

    for (auto v : adj[u])
    {
        if (!visisted[v])
        {
            par[v] = u;
            DFS(v, u);
        }
        else if (v != p) 
        {
            Print(v, u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("CAU6.inp", "r", stdin);

    cin >> n;

    int u, v;
    while (cin >> u >> v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int u = 1; u <= n; u++) if (!visisted[u]) DFS(1, -1);
    cout << "NO";

    return 0;
}