#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const LOG = 17;

int n, m;
vector<int> adj[N];
vector<int> tmpAdj[N];

vector<int> bcAdj[2 * N];
vector<int> bridgeAdj[N];

int in[N], low[N];
int timer = 0;

int ccId[N], bccId[N];
int cc = 0, bcc = 0;

int upCut[2 * N][20];
int upBridge[2 * N][20];

int hCut[2 * N], hBridge[N];
int cnt[2 * N];
bool cut[2 * N];

int cntRep[N];

stack<int> st1, st2;

void Tarjan(int u, int p)
{
    low[u] = in[u] = ++timer;
    st1.push(u);
    st2.push(u);

    for (auto &v : adj[u]) if (v != p)
    {
        if (in[v]) mini(low[u], in[v]);
        else
        {
            Tarjan(v, u);
            mini(low[u], low[v]);

            if (low[v] >= in[u])
            {
                tmpAdj[u].push_back(++bcc);
                int node = 0;

                while (node != v)
                {
                    node = st1.top(); st1.pop();
                    tmpAdj[node].push_back(bcc);
                }
            }
        } 
    }

    if (low[u] == in[u])
    {
        int v = 0;
        cc++;

        while (v != u)
        {
            v = st2.top(); st2.pop();
            in[v] = n + 1;
            ccId[v] = cc;
        }
    }
}

void DFS(int u, vector<int> adj[], int up[][20], int h[], bool count = false)
{
    for (auto &v : adj[u]) if (v != up[u][0])
    {
        if (count) cnt[v] = cnt[u] + cut[v];
        else cntRep[v] = cntRep[u] + (upper_bound(all(bridgeAdj[u]), v) -
                                     lower_bound(all(bridgeAdj[u]), v) - 1 > 0);

        h[v] = h[u] + 1;
        up[v][0] = u;

        FOR(i, 1, LOG) up[v][i] = up[up[v][i - 1]][i - 1];
        DFS(v, adj, up, h, count);
    }
}

int LCA(int u, int v, int up[][20], int h[])
{
    if (h[u] < h[v]) swap(u, v);
    FORD(i, LOG, 0) if (up[u][i] && h[up[u][i]] >= h[v]) u = up[u][i];
    if (u == v) return u;
    
    FORD(i, LOG, 0) if (up[u][i] != up[v][i])
    {
        u = up[u][i];
        v = up[v][i];
    }

    return up[u][0];
}

int QueryBride(int u, int v)
{
    int p = LCA(u, v, upBridge, hBridge);
    return  hBridge[u] + hBridge[v] - 2 * hBridge[p] -
            (cntRep[u] + cntRep[v] - 2 * cntRep[p]);
}

int QueryCut(int u, int v)
{
    int p = LCA(u, v, upCut, hCut);
    return cnt[u] + cnt[v] - 2 * cnt[p] + cut[p];
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tarjan(1, -1);

    FOR(u, 1, n)
    {
        if (sz(tmpAdj[u]) >= 2)
        {
            bccId[u] = ++bcc;
            cut[bcc] = true;

            for (auto &v : tmpAdj[u])
            {
                bcAdj[bcc].push_back(v);
                bcAdj[v].push_back(bcc);
            }
        }
        else if (sz(tmpAdj[u]) == 1) bccId[u] = tmpAdj[u][0];
    }

    FOR(i, 1, n) for (auto &j : adj[i])
    {
        int u = ccId[i];
        int v = ccId[j];
        if (u != v) bridgeAdj[u].push_back(v);
    }

    FOR(u, 1, cc) sort(all(bridgeAdj[u]));

    DFS(1, bridgeAdj, upBridge, hBridge);
    DFS(1, bcAdj, upCut, hCut, true);

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        cout << QueryCut(bccId[u], bccId[v]) + !cut[bccId[u]] + (u != v) * !cut[bccId[v]] 
             << ' ' << QueryBride(ccId[u], ccId[v]) << '\n';
    }

    return 0;
}