#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, k;
vector<pair<int, int>> adj[N];

bool mark[N];
int sMark[N], sMarkPar[N];

long long s[N], f[N], g[N];
long long sPar[N], fPar[N];
long long res[N];

void DFSPrepare(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F;
        int w = e.S;
        if (v == p) continue;

        DFSPrepare(v, u);

        if (sMark[v])
        {
            if (f[v] + w > f[u]) 
            {
                g[u] = f[u];
                f[u] = f[v] + w;
            }
            else maxi(g[u], f[v] + w);

            s[u] += s[v] + w;
            sMark[u] += sMark[v];
        }
    }
}

void DFS(int u, int p)
{
    for (auto &e : adj[u]) 
    {
        int v = e.F;
        int w = e.S;

        if (v == p) continue;

        if (sMarkPar[u] || (sMark[u] > sMark[v]))
        {   
            long long maxChild = (f[u] == f[v] + w && sMark[v]) ? g[u] : f[u];
            fPar[v] = max(maxChild, fPar[u]) + w;
            sPar[v] += sPar[u] + s[u] - (sMark[v] ? s[v] + w : 0) + w;
            sMarkPar[v] += sMark[u] + sMarkPar[u] - sMark[v] - mark[u];
        }

        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    FOR(i, 1, k)
    {
        int u; cin >> u;
        sMark[u] = sMarkPar[u] = 1;
    }    

    DFSPrepare(1, -1);
    DFS(1, -1);

    FOR(u, 1, n) cout << 2 * (s[u] + sPar[u]) - max(f[u], fPar[u]) << '\n'; 
    // FOR(u, 1, n) cout << sPar[u] + s[u] << ' ';
    // FOR(u, 1, n) cout << sPar[u] << ' ';

    // cout << fPar[3];
    // cout << g[1];

    return 0;
}