#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, m;
vector<int> adj[N];
vector<int> dagAdj[N];

int in[N], low[N];
int sccId[N];
bool inDeg[N], outDeg[N];

stack<int> st;
int cnt = 0, scc = 0;

void Tarjan(int u)
{
    low[u] = in[u] = ++cnt;
    st.push(u);

    for (auto &v : adj[u])
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

void Reset()
{
    memset(inDeg, false, sizeof inDeg);
    memset(outDeg, false, sizeof outDeg);

    memset(sccId, 0, sizeof sccId);
    memset(in, 0, sizeof in);
    
    scc = cnt = 0;

    FOR(u, 1, n)
    {
        adj[u].clear();
        dagAdj[u].clear();
    }
}

bool Solve()
{
    bool st = false;
    bool ed = false;

    FOR(u, 1, scc) 
    {
        if (inDeg[u] == false)
        {
            if (st) return false;
            st = true;
        }

        if (outDeg[u] == false)
        {
            if (ed) return false;
            ed = true;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        Reset();

        cin >> n >> m;
        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        FOR(u, 1, n) if (!in[u] && sz(adj[u])) Tarjan(u);
        FOR(i, 1, n) for (auto &j : adj[i])
        {
            int u = sccId[i];
            int v = sccId[j];

            if (u == v) continue;
            dagAdj[u].push_back(v);
        }
    
        FOR(u, 1, n)
        {
            sort(all(dagAdj[u]));
            dagAdj[u].erase(unique(all(dagAdj[u])), dagAdj[u].end());

            for (auto &v : dagAdj[u]) if (!inDeg[v])
            {
                inDeg[v] = true;
                outDeg[u] = true;   
            }
        }

        cout << (Solve() ? "YES\n" : "NO\n");
    }
    
    return 0;
}