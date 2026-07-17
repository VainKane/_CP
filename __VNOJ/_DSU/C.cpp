#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct DSU
{
    vector<int> par;
    vector<int> sz;
    vector<int> val;
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
        par.assign(n + 2, 0);
        sz.assign(n + 2, 0);
        val.assign(n + 2, 0);

        if (n) MakeSet();
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

int const N = 1e5 + 5;

int n, k;
DSU dsu;

int pen[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    dsu = DSU(n);

    while (k--)
    {
        string op; cin >> op;
        int x, y;

        if (op == "join") 
        {
            cin >> x >> y;
            dsu.Union(x, y);
        }
        else if (op == "add")
        {
            cin >> x >> y;
            dsu.val[dsu.Find(x)] += y;
        }
        else
        {
            cin >> x; 
            cout << dsu.val[dsu.Find(x)] << '\n';
        }
    }

    return 0;
}