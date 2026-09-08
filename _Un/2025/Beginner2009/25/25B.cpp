#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int v, l;
};

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int q;

vector<Node> adj[N];

int h[N];
int up[N][LOG + 4];
long long upLength[N][LOG + 4];

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

void DFS(int u)
{
    for (auto node : adj[u])
    {
        int v = node.v;
        // if (v == up[u][0]) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;
        upLength[v][0] = node.l;

        for (int i = 1; i <= LOG; i++)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
            upLength[v][i] = upLength[v][i - 1] + upLength[up[v][i - 1]][i - 1];
        }

        DFS(v);
    }
}

long long LCA(int u, int v)
{
    if (h[v] > h[u]) swap(u, v);
    int d = h[u] - h[v];

    long long res = 0;

    for (int i = LOG; i >= 0; i--)
    {
        if (bit(i, d))
        {
            res += upLength[u][i];
            u = up[u][i];
        }
    }

    if (u == v) return res;

    for (int i = LOG; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            res += upLength[u][i];
            res += upLength[v][i];

            u = up[u][i];
            v = up[v][i];
        }
    }

    res += upLength[u][0];
    res += upLength[v][0];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (1)
    {
        cin >> n;
        if (!n) break;

        for (int i = 0; i < n; i++) adj[i].clear();

        for (int i = 1; i < n; i++)
        {
            int a, l;
            cin >> a >> l;

            adj[a].push_back({i, l});
        }

        DFS(0);

        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            cout << LCA(u, v) << ' ';
        }

        cout << '\n';
    }

    return 0;
}