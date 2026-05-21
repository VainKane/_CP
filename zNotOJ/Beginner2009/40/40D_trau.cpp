#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 5;
int const K = 15;

int t;
int n, k;
int root;

int a[N];
vector<int> adj[N];
int f[N][K];

int res;
int cnt;
int outDeg[N];

void DFS(int u, int p)
{
    for (auto v : adj[u])
    {
        if (v == p) continue;
        DFS(v, u);
        
        for (int i = k; i >= 1; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                f[u][i] = max(f[u][i], f[u][i - j] + f[v][j]);
            }
        }
    }
    
    f[u][1] = max(f[u][1], a[u]);
}

void Reset()
{
    for (int i = 1; i <= n; i++) adj[i].clear();
    memset(outDeg, 0, sizeof outDeg);
    memset(f, 0, sizeof f);
    res = 0;
    cnt = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Reset();

        for (int i = 1; i <= n; i++)
        {
            int p;
            cin >> p >> a[i];
            if (p) 
            {
                adj[p].push_back(i);
                outDeg[p]++;
            }
            else root = i;
        }

        for (int i = 1; i <= n; i++) cnt += (outDeg[i] == 0);

        if (cnt >= k) DFS(root, -1);
        cout << f[root][k] << '\n';
    }

    return 0;
}