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
    int type, u, v;

    void Input(int _type)
    {
        type = _type;
        if (type != 2) cin >> u;
        else cin >> u >> v;
    }
};

int const N = 5e4 + 5;
int const M = 2.5e5 + 5;
int const BK = 244;
int const GR = N / BK + 5;

int n, m, q;

bool online[N];
unordered_map<int, bool> mp[N];

Query qr[M];

int hvId[N], node[GR];
int hv = 0;

int cnt[N];

void Init()
{
    FOR(i, 1, q) if (qr[i].type == 2)
    {
        mp[qr[i].u][qr[i].v];
        mp[qr[i].v][qr[i].u];
    }

    FOR(u, 1, n) if (sz(mp[u]) > BK) 
    {
        hvId[u] = ++hv;
        node[hvId[u]] = u;
    }

    FOR(u, 1, n) if (!hvId[u] && online[u]) for (auto &p : mp[u]) cnt[p.F] += p.S * mp[u][p.F];
}

void Update(int u, int v)
{
    mp[u][v] ^= 1;
    mp[v][u] ^= 1;

    int delta = mp[u][v] == 1 ? 1 : -1;

    if (!hvId[v]) cnt[u] += online[v] * delta;
    if (!hvId[u]) cnt[v] += online[u] * delta;
}

int Query(int u)
{
    int res = cnt[u];
    FOR(i, 1, hv) res += mp[u][node[i]] * online[node[i]];
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
        mp[u][v] = mp[v][u] = true;
    }

    FOR(i, 1, q)
    {
        char type; cin >> type;
        if (type == 'O' || type == 'F') qr[i].Input(1);
        else if (type == 'A' || type == 'D') qr[i].Input(2);
        else qr[i].Input(3);
    }

    Init();

    FOR(i, 1, q)
    {
        if (qr[i].type == 1) 
        {
            int u = qr[i].u;
            
            online[u] ^= 1;
            int delta = online[u] ? 1 : -1;

            if (!hvId[u]) for (auto &p : mp[u]) cnt[p.F] += delta * p.S;
        }
        else if (qr[i].type == 2) Update(qr[i].u, qr[i].v);
        else cout << Query(qr[i].u) << '\n';
    }

    return 0;
}