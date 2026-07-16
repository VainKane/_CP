#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);
        MakeSet();
    }

    int Find(int v)
    {
        if (v == par[v]) return v;
        return par[v] = Find(par[v]);
    }

    bool Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;

        return true;
    }
};

int const N = 109;

int n, m;
DSU dsu[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m) dsu[i] = DSU(n);

    FOR(i, 1, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        dsu[c].Union(u, v);
    }

    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int res = 0;
        FOR(c, 1, m) res += dsu[c].Find(u) == dsu[c].Find(v);
        cout << res << '\n';
    }

    return 0;
}