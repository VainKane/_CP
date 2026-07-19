#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "GEORGE"

int const N = 1e3 + 5;

int n, m;
int a, b, k, g;

int p[N];
int c[N][N];
int in[N][N];

int d[N];

void Init()
{
    memset(in, 0x3f, sizeof in);

    int s = 0; 
    FOR(i, 1, g - 1)
    {
        int u = p[i];
        int v = p[i + 1];

        in[u][v] = in[v][u] = s;
        s += c[u][v];
    }
}

void Dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({k, s});

    memset(d, 0x3f, sizeof d);
    d[s] = k;

    while (!pq.empty())
    {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;
    
        FOR(v, 1, n)
        {
            if (!c[u][v]) continue;

            int w = c[u][v];
            int en = in[u][v] + c[u][v];

            if (d[u] >= in[u][v] && d[u] < en) w += en - d[u];
            
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    cin >> a >> b >> k >> g;
    FOR(i, 1, g) cin >> p[i];
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = c[v][u] = w;
    }

    Init();
    Dijkstra(a);

    cout << d[b] - k;

    return 0;
}