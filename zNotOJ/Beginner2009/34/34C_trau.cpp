#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;
int q;

vector<int> adj[N];

bool visisted[N];

int banU;
int banV;
int banCut;

void DFS(int u)
{
    visisted[u] = true;
    for (auto v : adj[u])
    {
        if (visisted[v]) continue;
        if (min(u, v) == banU && max(u, v) == banV) continue;
        if (u == banCut || v == banCut) continue;

        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> q;
    while (q--)
    {
        int type, a, b, c, d;
        cin >> type;

        memset(visisted, 0, sizeof visisted);

        if (type == 1)
        {
            cin >> a >> b >> c >> d;
            banU = min(c, d);
            banV = max(c, d);
            banCut = 0;

            DFS(a);
            if (visisted[b]) cout << "yes\n";
            else cout << "no\n";
        }
        else
        {
            cin >> a >> b >> c;
            banU = 0;
            banV = 0;
            banCut = c;

            DFS(a);
            if (visisted[b]) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}