#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
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

struct Query
{
    char type;
    int u, v;

    void Input()
    {
        cin >> type;
        if (type == 'A' || type == 'D') cin >> u >> v;
        else cin >> u;
    }
};

int const N = 5e4 + 5;
int const M = 2.5e5 + 5;
int const BK = 500;

int n, m, q;
bool online[N];

vector<int> adj[N];
vector<int> hvAdj[N];
vector<int> everAdj[N];

Query qr[M];

int hvId[N];
int hv = 0;

int cnt[N];

void Init()
{
    FOR(u, 1, n) everAdj[u] = adj[u];
    FOR(i, 1, q) if (qr[i].type == 2)
    {
        everAdj[qr[i].u].push_back(qr[i].v);
        everAdj[qr[i].v].push_back(qr[i].u);
    }

    FOR(u, 1, n)
    {
        sort(all(everAdj[u]));
        everAdj[u].erase(unique(all(everAdj[u])), everAdj[u].end());
    }

    FOR(u, 1, n) if (sz(everAdj[u]) > BK) hvId[u] = ++hv;
    FOR(u, 1, n) if (!hvId[u] && online[u]) for (auto &v : adj[u]) cnt[v]++;
    FOR(u, 1, n) for (auto &v : adj[u]) if (hvId[v]) hvAdj[u].push_back(v);
}

void Update(int u)
{
    online[u] ^= 1;
    int delta = online[u] ? 1 : -1;
    if (!hvId[u]) for (auto &v : adj[u]) cnt[v] += delta;
}

void Add(int u, int v)
{
    adj[u].push_back(v);
    if (hvId[v]) hvAdj[u].push_back(v);
    else cnt[u] += online[v];
}

void Sub(int u, int v)
{
    vector<int> haha;

    if (hvId[v])
    {
        haha = hvAdj[u];
        hvAdj[u].clear();
        for (auto &node : haha) if (node != v) hvAdj[u].push_back(node);
    }
    else cnt[u] -= online[v];

    if (!hvId[u])
    {
        haha = adj[u];
        adj[u].clear();
        for (auto &node : haha) if (node != v) adj[u].push_back(node);
    }
}

int Query(int u)
{
    int res = cnt[u];
    for (auto &v : hvAdj[u]) res += online[v];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;

    int o; cin >> o;
    while (o--)
    {
        int id; cin >> id;
        online[id] = true;
    }

    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, q) qr[i].Input();
    
    Init();

    FOR(i, 1, q)
    {
        int u = qr[i].u;
        int v = qr[i].v;

        if (qr[i].type == 'O' || qr[i].type == 'F') Update(u);
        else if (qr[i].type == 'A') Add(u, v), Add(v, u);
        else if (qr[i].type == 'D') Sub(u, v), Sub(v, u);
        else cout << Query(u) << '\n';
    }

    return 0;
}