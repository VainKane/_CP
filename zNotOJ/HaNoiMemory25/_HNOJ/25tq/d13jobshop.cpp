#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 109;

int n, m;
vector<int> adj[N];

bool visited[N];
bool inCycle[N];

int d[N];
int inDeg[N];

void BFS()
{
    queue<int> q;
    FOR(u, 1, n) if (inDeg[u] == 0) 
    {
        q.push(u);
        d[u] = 1;
    }

    int cnt = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;

        for (auto &v : adj[u])
        {
            if (--inDeg[v] == 0) q.push(v);
            d[v] = d[u] + 1;
        }
    }

    if (cnt != n) cout << -1;
    else cout << *max_element(d + 1, d + n + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n)
    {
        int k; cin >> k;
        while (k--)
        {
            int u; cin >> u;
            adj[u].push_back(i);
            inDeg[i]++;
        }
    }

    if (n <= m) BFS();
    else cout << 2;

    return 0;
}