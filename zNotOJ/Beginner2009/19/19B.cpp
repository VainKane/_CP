#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
};

int const N = 1e5 + 10;

int n;
int m;
int s;
int t;

vector<int> adj[N];
bool visisted[N];
int trace[N];
int h[N];

Edge a[N];

vector<int> res;
int target;

void DFS(int u)
{
    visisted[u] = true;

    for (auto v : adj[u])
    {
        if (!visisted[v])
        {
            trace[v] = u;
            DFS(v);
        }
    }
}

void BFS(int st)
{
    queue<int> qu;
    qu.push(st);

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u])
        {
            if (!visisted[v])
            {
                visisted[v] = true;
                trace[v] = u;

                qu.push(v);
            }
        }
    }
}

void Cal(int height)
{
    for (int i = 1; i <= m; i++)
    {
        if (a[i].w >= height)
        {
            adj[a[i].u].push_back(a[i].v);
            adj[a[i].v].push_back(a[i].u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    // freopen("19B.inp", "r", stdin);
    // freopen("19B.out", "w", stdout);

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }

    int l = 1;
    int r = 1e9;
    h[s] = INT_MAX;

    int k = 0;

    while (l <= r)
    {
        memset(visisted, 0, sizeof visisted);
        for (int i = 1; i <= m; i++) adj[i].clear();

        int mid = l + (r - l) / 2;
        Cal(mid);
        BFS(s);

        if (visisted[t])
        {
            k = mid;
            l = mid + 1;

            res.clear();
            int u = t;
            while (u != s)
            {
                res.push_back(u);
                u = trace[u];
            }
            res.push_back(s);
        }
        else r = mid - 1;
    }
    
    cout << k << '\n';
    if (res.size() > 0) cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';

    return 0;
}