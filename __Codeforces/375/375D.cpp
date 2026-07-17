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

int const N = 1e5 + 5;
int const BK = sqrt(N);

int in[N], out[N];

struct Query
{
    int l, r, k, id;

    Query()
    {
        l = r = k = id = 0;
    }

    void Input(int &_id)
    {
        id = _id;
        cin >> l >> k;
        r = out[l];
        l = in[l];
    }

    bool operator < (Query const other) const
    {
        if (l / BK != other.l / BK) return l < other.l;
        if ((l / BK) & 1) return r < other.r;
        return r > other.r;
    }
};

int n, m;

int a[N];
vector<int> adj[N];

Query qr[N];

int node[N];
int timer = 0;

int cnt[N];
int f[N];

int res[N];

void DFS(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    for (auto &v : adj[u]) if (v != p) DFS(v, u);
    out[u] = timer;
}

void UpdateSub(int val)
{
    f[cnt[val]--]--;
}

void UpdateAdd(int val)
{
    f[++cnt[val]]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    FOR(i, 1, m) qr[i].Input(i);
    sort(qr + 1, qr + m + 1);

    int l = 1, r = 0;

    FOR(i, 1, m)
    {
        while (r < qr[i].r) UpdateAdd(a[node[++r]]);
        while (r > qr[i].r) UpdateSub(a[node[r--]]);
        
        while (l > qr[i].l) UpdateAdd(a[node[--l]]);
        while (l < qr[i].l) UpdateSub(a[node[l++]]);

        res[qr[i].id] = f[qr[i].k];
    }

    FOR(i, 1, m) cout << res[i] << '\n';

    return 0;
}