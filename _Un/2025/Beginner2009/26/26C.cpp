#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 109;

int n, m; 
int h1, s1;
int h2, s2;

int dh1[N];
int dh2[N];
int ds1[N];
int ds2[N];

int trace1[N];
int trace2[N];

vector<Edge> adj[N];

vector<int> path1;
vector<int> path2;

int node = 0;

int t = -1;

void Dijkstra(int s, int d[], int trace[])
{
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du > d[u]) continue;

        for (auto e : adj[u])
        {
            int v = e.v;
            int w = e.w;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (d[v] == t) v = node;
                pq.push({d[v], v});
                trace[v] = u;
            }
        }
    }
} 

void GetPath(vector<int> &path, int trace[], int s, int t)
{
    path.push_back(t);
    while (s != t)
    {
        path.push_back(t = trace[t]);
    }
    reverse(path.begin(), path.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> h1 >> s1 >> h2 >> s2;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(dh1, 0x3f, sizeof dh1);
    memset(dh2, 0x3f, sizeof dh2); 
    memset(ds1, 0x3f, sizeof ds1);
    memset(ds2, 0x3f, sizeof ds2);   

    Dijkstra(s1, ds1, trace1);
    Dijkstra(s2, ds2, trace1);
    Dijkstra(h1, dh1, trace1);
    Dijkstra(h2, dh2, trace1);

    t = 1e9;

    for (int i = 1; i <= n; i++)
    {
        if (ds1[i] + dh1[i] != dh1[s1]) continue;
        if (ds2[i] + dh2[i] != dh2[s2]) continue;
        if (dh1[i] != dh2[i]) continue;

        if (t > dh1[i])
        {
            node = i;
            t = dh1[i];
        }
    }

    if (!node)
    {
        cout << "NO";
        exit(0);
    }

    memset(dh1, 0x3f, sizeof dh1);
    memset(dh2, 0x3f, sizeof dh2);

    Dijkstra(h1, dh1, trace1);
    Dijkstra(h2, dh2, trace2);

    GetPath(path1, trace1, h1, s1);
    GetPath(path2, trace2, h2, s2);

    cout << "YES\n";
    cout << dh1[s1] << '\n';
    for (auto val : path1) cout << val << ' ';
    cout << '\n';
    cout << dh2[s2] << '\n';
    for (auto val : path2) cout << val << ' ';
    cout << '\n';
    cout << node << '\n';
    cout << dh1[node];

    return 0;
}