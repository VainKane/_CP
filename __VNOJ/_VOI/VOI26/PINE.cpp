#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define ALL(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "PINE"

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
    int x, y, w;

    void Input()
    {
        cin >> x >> y >> w;
    }
};

int const N = 2e5 + 5;

int n, q;

int a[N];
vector<int> adj[N];
Query qr[N];

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 5000 && q <= 5000;
    }

    int h[5009];
    int par[5009];

    void DFS(int u, int p)
    {
        for (auto &v : adj[u]) if (v != p)
        {
            h[v] = h[u] + 1;
            par[v] = u;
            DFS(v, u);
        }
    }

    void Update(int u, int v, int &w)
    {
        if (h[u] < h[v]) swap(u, v);

        a[u] %= w;
        a[v] %= w;

        while (h[u] > h[v])
        {
            u = par[u];
            a[u] %= w;
        }

        if (u == v) return;

        while (u != v)
        {
            u = par[u];
            v = par[v];

            a[u] %= w;
            a[v] %= w;
        }
    }

    void Process()
    {
        DFS(1, -1);

        FOR(i, 1, q)
        {
            Update(qr[i].x, qr[i].y, qr[i].w);

            long long res = 0;
            FOR(idx, 1, n) res += a[idx] % i;
            cout << res << '\n';
        }
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        FOR(u, 1, n)
        {
            if (a[u] > 2) return false;
            for (auto &v : adj[u]) if (abs(u - v) != 1) return false;
        }

        return true;
    }

    vector<int> pos[3];

    void Process()
    {
        FOR(i, 1, n) if (a[i]) pos[a[i]].push_back(i);

        int res = 0;

        FOR(t, 1, q)
        {
            if (qr[t].x > qr[t].y) swap(qr[t].x, qr[t].y);
            if (qr[t].w <= 2)
            {
                int u = qr[t].w == 1 ? 1 : 2;

                FOR(k, u, 2)
                {
                    int l = lower_bound(ALL(pos[k]), qr[t].x) - pos[k].begin();
                    int r = upper_bound(ALL(pos[k]), qr[t].y) - pos[k].begin() - 1;

                    FOR(i, l, r)
                    {
                        if (t > 3) res -= a[pos[k][i]];
                        a[pos[k][i]] = 0;
                    }

                    vector<int> tmp;
                    REP(i, l) tmp.push_back(pos[k][i]);
                    FOR(i, r + 1, sz(pos[k]) - 1) tmp.push_back(pos[k][i]);

                    pos[k] = tmp;
                }
            }

            if (t <= 2)
            {
                res = 0;
                FOR(i, 1, n) res += a[i] % t;
            }
            else if (t == 3)
            {
                res = 0;
                FOR(i, 1, n) res += a[i];
            }

            cout << res << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, q) qr[i].Input();

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub2::CheckSub()) return Sub2::Process(), 0;

    return 0;
}
