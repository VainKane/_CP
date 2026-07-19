#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const K = 1e3 + 5;

int t;
int n, k;

int a[N];

int in[N];
int out[N];

int w[N];
int outDeg[N];

vector<int> adj[N];

int root;
int res;
int cnt;
int last; 

int v[N];
int z[N];
int f[N][K];

int ok = 0;

bool cmp(int a, int b)
{
    return out[a] < out[b];
}

void DFS(int u, int p)
{
    in[u] = ++cnt;
    z[u] = last;

    for (auto v : adj[u])
    {
        if (v == p) continue;
        DFS(v, u);
    }
   
    out[u] = ++cnt;
    v[u] = last;
    last = u;
}

void Solve()
{
    DFS(root, -1);
    int last = 0;

    for (int i = 1; i <= n; i++) a[i] = i;
    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int u = a[i];
            f[u][j] = max(f[z[u]][j - 1] + w[u], f[v[u]][j]);
        }
    }

    // for (int i = 1; i <= cnt; i++) cout << b[i] << ' ';
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ' << z[a[i]] << '\n';
}

void Reset()
{
    for (int i = 1; i <= n; i++) adj[i].clear();
    memset(outDeg, 0, sizeof outDeg);
    memset(v, 0, sizeof v);
    memset(z, 0, sizeof z);
    root = 0;
    last = 0;
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
            cin >> p >> w[i];
            if (p) 
            {
                adj[p].push_back(i);
                outDeg[p]++;
            }
            else root = i;
        }

        for (int i = 1; i <= n; i++) ok += (outDeg[i] == 0);
        if (ok >= k) Solve();
        
        cout << f[a[n]][k] << '\n';
    }

    return 0;
}