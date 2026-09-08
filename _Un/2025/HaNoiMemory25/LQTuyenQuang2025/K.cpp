#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n;
vector<int> adj[N];

int f[N];

int in[N];
int cnt = 0;

void DFS(int u, int p)
{
    in[u] = ++cnt;
    f[u] = 1;

    for (auto &v : adj[u]) if (v != p)
    {
        DFS(v, u);
        f[u] += f[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    DFS(1, -1);

    long long res = 0;
    FOR(l, 1, n) FOR(r, l, n)
    {
    }

    cout << res << '\n';

    return 0;
}