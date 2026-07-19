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

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(l, val);
        Update(r + 1, -val);
    }

    long long Get(int idx)
    {
        long long res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }
};

int const N = 2e5 + 5;

int n, q;

int a[N];
vector<int> adj[N];

int in[N], out[N];
int timer = 0;

FenwickTree bit;

void DFS(int u, int p)
{
    in[u] = ++timer;

    for (auto &v : adj[u]) if (v != p) DFS(v, u);
    out[u] = timer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);
    bit = FenwickTree(n);

    FOR(u, 1, n) bit.Update(in[u], out[u], a[u]);

    while (q--)
    {
        int type, u, x;
        cin >> type >> u;

        if (type == 1)
        {
            cin >> x;
            bit.Update(in[u], out[u], x - a[u]);
            a[u] = x;
        }
        else cout << bit.Get(in[u]) << '\n';
    }

    return 0;
}