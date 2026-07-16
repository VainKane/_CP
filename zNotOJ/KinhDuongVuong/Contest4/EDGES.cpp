#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
long long const oo = 1e18;

int n;
int m1, m2;

vector<int> initAdj[N];
vector<pair<int, int>> adj[N];

int in[N], low[N];
int sccId[N];

bool inDeg[N], outDeg[N];
long long d[N];

stack<int> st;
int cnt = 0, scc = 0;
int s = 0, t = 0;

long long res = 0;

void Tarjan(int u)
{
    low[u] = in[u] = ++cnt;
    st.push(u);

    for (auto &v : initAdj[u])
    {
        if (sccId[v]) continue;
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v);
            mini(low[u], low[v]);
        }
    }

    if (low[u] == in[u])
    {
        int v = 0;
        scc++;

        while (v != u)
        {
            v = st.top();
            st.pop();

            sccId[v] = scc;
        }
    }
}

void Init()
{
    FOR(u, 1, n) if (!in[u]) Tarjan(u);
    FOR(i, 1, n) for (auto &j : initAdj[i])
    {
        int u = sccId[i];
        int v = sccId[j];
        if (u == v) continue;
        inDeg[v] = true;
        outDeg[u] = true;
    }

    FOR(i, 1, scc) if (!inDeg[i])
    {
        FOR(u, 1, n) if (sccId[u] == i) 
        {
            s = u;
            break;
        }
        break;
    }

    FOR(i, 1, scc) if (!outDeg[i])
    {
        FOR(u, 1, n) if (sccId[u] == i) 
        {
            t = u;
            break;
        }
        break;
    }
}

void Dijkstra()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, t});

    memset(d, 0x3f, sizeof d);
    d[t] = 0;

    while (!pq.empty())
    {
        int u = pq.top().S;
        long long du = pq.top().F;
        pq.pop();

        if (du > d[u]) continue;

        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = e.S;

            if (mini(d[v], d[u] + w)) pq.push({d[v], v});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    cin >> m1;
    FOR(i, 1, m1)
    {
        int u, v;
        cin >> u >> v;
        initAdj[u].push_back(v);
        adj[u].push_back({v, 0});
    }

    cin >> m2;
    FOR(i, 1, m2)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        if (w < 0)
        {
            res += w;
            w = 0;
        }
        adj[u].push_back({v, w});
    }
    
    Init();
    Dijkstra();

    if (d[s] < oo) cout << "YES\n" << res + d[s];
    else cout << "NO";

    return 0;
}