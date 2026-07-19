#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int const N = 1e5 + 5;

int n;
int m;

vector<int> adj[N];
bool visisted[N];

vector<int> topo;
int pos[N];

int low[N];
int id[N];

int cnt = 0;
int scc = 0;

vector<int> ahihi[3];
stack<int> st;

int in[N];
set<int> dagAdj[N];

int inDeg[N];
int outDeg[N];

vector<int> vDag;

void Tarjan(int u)
{
    low[u] = id[u] = ++cnt;
    st.push(u);
    
    for (auto v : adj[u])
    {
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == id[u])
    {
        scc++;

        int v = 0;
        while (v != u)
        {
            v = st.top();
            st.pop();

            id[v] = n + 1;
            in[v] = u;
        }

        vDag.pb(u);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
    }

    for (int i = 1; i <= n; i++) if (!id[i]) Tarjan(i);

    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            if (in[u] == in[v]) continue;
            dagAdj[in[u]].insert(in[v]);
            inDeg[in[v]]++;
            outDeg[in[u]]++;
        }
    }

    int a = 0;
    int b = 0;

    if (scc == 1) cout << "NO";
    
    for (auto u : vDag)
    {
        if (inDeg[u] == 0)
        {
            if (a)
            {
                cout << "NO";
                return 0;
            }
            a = u;
        }
        if (outDeg[u] == 0)
        {
            if (b)
            {
                cout << "NO";
                return 0;
            }
            b = u;
        }
    }

    cout << "YES\n";
    cout << b << ' ' << a;

    return 0;
}