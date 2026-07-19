#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

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
        if (par[v] == v) return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;
        
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

int const N = 3e5 + 5;

int n, m;
DSU dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    dsu = DSU(n);

    REP(i, n)
    {
        int x; cin >> x;
        dsu.Union(i, x);
    }

    vector<int> v;

    REP(i, n) v.push_back(dsu.Find(i));
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    int res = sz(v);

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        int k = dsu.Find(x) == dsu.Find(y) ? 1 : -1;
        cout << res + k << '\n'; 
    }

    return 0;
}