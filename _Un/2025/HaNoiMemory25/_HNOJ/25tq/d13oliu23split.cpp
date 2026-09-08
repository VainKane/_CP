#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e6 + 5;

int n, k;
int w[N];
vector<int> adj[N];

int topo[N];
int m = 0;

long long f[N];
int par[N];

long long sum = 0;

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p) 
    {
        par[v] = u;
        DFS(v, u);
    }

    topo[++m] = u;
}

bool Check(long long const &x)
{
    FOR(i, 1, n) f[topo[i]] = w[topo[i]];
    int cnt = 0;

    FOR(i, 1, n)
    {
        if (f[topo[i]] >= x) cnt++;
        else f[par[topo[i]]] += f[topo[i]];
    }

    return cnt >= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> w[i], sum += w[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    long long l = 1;
    long long r = sum / k;
    long long res = l;

    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (Check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res;

    return 0;
}