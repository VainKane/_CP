#include <bits/stdc++.h>

using namespace std;

int const N = 100009;

int n;
vector<int> adj[N];
bool visisted[N];
int par[N];

void Print(int start, int end)
{
    vector<int> res;

    res.push_back(start);
    while (end != start)
    {
        res.push_back(end);
        end = par[end];
    } 
    res.push_back(start);
     
    reverse(res.begin(), res.end());

    cout << "YES\n";
    for (auto val : res) cout << val << ' ';

    exit(0);
}


void DFS(int u)
{
    visisted[u] = true;

    for (auto v : adj[u])
    {
        if (!visisted[v])
        {
            par[v] = u;
            DFS(v);
        }
        else if (v != par[u]) 
        {
            Print(v, u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int u, v;
    while (cin >> u >> v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);
    cout << "NO";

    return 0;
}