#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

struct Edge
{
    int u, v;

    int GetOther(int p)
    {
        return p ^ u ^ v;
    }
};

int const N = 509;
int const M = 1e5 + 5;

int n, m;
vector<int> adj[N];
Edge edges[M];

bool visited[N];
bool inCycle[N];

int par[N];

vector<int> cycleVertices;
stack<int> st;

int startPos = -1, endPos;

void DFSPrepare(int u)
{
    visited[u] = inCycle[u] = true;

    for (auto &id : adj[u])
    {
        int v = edges[id].GetOther(u);
        
        if (inCycle[v] && startPos == -1) 
        {
            startPos = v;
            endPos = u;

            while (endPos != startPos)
            {
                cycleVertices.push_back(endPos);
                endPos = par[endPos];
            }

            cycleVertices.push_back(startPos);
            reverse(all(cycleVertices));
            cycleVertices.push_back(cycleVertices[0]);
            
            return;
        }

        if (visited[v]) continue;

        par[v] = u;
        DFSPrepare(v);
    }

    inCycle[u] = false;
}

bool DFS(int u, int banned)
{
    visited[u] = inCycle[u] = true;

    for (auto &id : adj[u]) if (id != banned)
    {
        int v = edges[id].GetOther(u);

        if (inCycle[v]) return true;
        if (visited[v]) continue;
        if (DFS(v, banned)) return true;
    }      

    inCycle[u] = false;
    return false;
}

bool Solve()
{
    if (startPos == -1) return true;
    FOR(i, 0, sz(cycleVertices) - 2)
    {
        int u = cycleVertices[i];
        for (auto &id : adj[u]) if (edges[id].GetOther(u) == cycleVertices[i + 1])
        {
            memset(visited, false, sizeof visited);
            memset(inCycle, false, sizeof inCycle);

            bool ok = true;
            FOR(u, 1, n) if (!visited[u]) if (DFS(u, id))
            {
                ok = false;
                break;
            }

            // if (ok) cout << "edge: " << id << '\n';
            if (ok) return true;

            // cout << "sus edge: " <<  id << '\n';
            break;
        }
    }

    return false;
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
        edges[i] = {u, v};
        adj[u].push_back(i);
    }

    FOR(u, 1, n) if (!visited[u]) 
    {
        DFSPrepare(u);
        if (startPos != -1) break;
    }

    cout << (Solve() ? "YES" : "NO");

    return 0;
}