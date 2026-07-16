#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int v, w;
};

int const N = 1e5 + 5;

int n;
int m;
int s;
int t;

long long d[N];
bool visisted[N];

vector<Edge> a[N];

void Dijkstra(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;   

    priority_queue<pair<int, int>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (visisted[u]) continue;
        visisted[u] = true;
        
        for (auto e : a[u])
        {
            int v = e.v;
            int w = e.w;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({-d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    Dijkstra(s);
    cout << d[t];

    return 0;
}