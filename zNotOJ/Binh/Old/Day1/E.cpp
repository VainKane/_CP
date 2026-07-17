#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n, k;
vector<int> adj[N];

int f[N];

int DFS(int u, int p, int &l)
{
    int res = 0;
    vector<int> d = {0};

    for (auto v : adj[u]) if (v != p)
    {
        res += DFS(v, u, l);
        d.push_back(f[v] + 1);
    }

    sort(all(d));
    int i = d.size() - 1;
    while (i && d[i] + d[i - 1] > l) i--, res++;

    f[u] = d[i];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l = 0;
    int r = n - 1;
    int res = n - 1;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (DFS(1, -1, mid) <= k)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}