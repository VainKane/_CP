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

struct State
{
    int u, len, cnt, du;
    bool used;

    State(int _u = 0, int _len = 0, int _cnt = 0, bool _used = 0, int _du = 0)
    {
        u = _u, len = _len, cnt = _cnt, used = _used, du = _du;
    }

    bool operator < (State const other) const
    {
        return du > other.du;
    }
};

int const N = 109;
int const oo = 1e9 + 9;

int a, b, m, l, k;
vector<pair<int, int>> adj[N];

int d[N][509][12][2];

void Dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[a + b][0][0][0] = 0;

    priority_queue<State> pq;
    #define PS(u, len, cnt, used) pq.push(State(u, len, cnt, used, d[u][len][cnt][used]));

    PS(a + b, 0, 0, 0);

    if (k)
    {
        d[a + b][0][1][1] = 0;
        PS(a + b, 0, 1, 1);
    }

    while (!pq.empty())
    {
        int u = pq.top().u;
        int len = pq.top().len;
        int cnt = pq.top().cnt;
        bool used = pq.top().used;
        int du = pq.top().du;
        pq.pop();

        if (du > d[u][len][cnt][used]) continue;

        if (!used && cnt < k && mini(d[u][0][cnt + 1][1], du)) PS(u, 0, cnt + 1, 1);
        if (used && mini(d[u][0][cnt][0], du)) PS(u, 0, cnt, 0);

        if (used && u > a && len) continue;
        for (auto &e : adj[u])
        {
            int v = e.F;
            int w = used ? 0 : e.S;
            int nLen = used ? len + e.S : len;

            if (used && nLen > l) continue;
            if (mini(d[v][nLen][cnt][used], du + w)) PS(v, nLen, cnt, used);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> a >> b >> m >> l >> k;
        
        FOR(u, 1, a + b) adj[u].clear();
        FOR(i, 1, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        Dijkstra();

        int res = oo;
        FOR(cnt, 0, k) mini(res, d[1][0][cnt][0]);
        cout << res << '\n';
    }

    return 0;
}