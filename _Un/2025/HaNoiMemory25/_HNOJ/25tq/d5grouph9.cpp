#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n, m;
vector<int> adj[N];

int initDeg[N];
int deg[N];

int BFS(int l, int r, int k)
{
    FOR(i, 1, n) deg[i] = initDeg[i];

    queue<int> q;
    FOR(i, l, r) if (deg[i] < k) q.push(i);
    FOR(i, 1, l - 1) q.push(i);
    FOR(i, r + 1, n) q.push(i);

    int cnt = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u >= l && u <= r) cnt++;

        for (auto &v : adj[u])
        {
            if (--deg[v] == k - 1) q.push(v);
        }
    }

    return r - l + 1 - cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        initDeg[u]++; initDeg[v]++;
    }

    int t; cin >> t;
    while (t--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << BFS(l, r, k) << '\n';
    }

    return 0;
}