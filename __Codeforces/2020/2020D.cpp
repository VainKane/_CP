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

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int sets = 0;
    int n;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }

        sets = n;
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
        sets--;
    }
};

int const N = 2e5 + 5;

int n, m;
DSU dsu;

int maxR[11][N];
bool used[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;
        dsu = DSU(n);

        FOR(d, 1, 10) memset(maxR[d], 0, (n + 1) * 4);

        while (m--)
        {
            int a, d, k;
            cin >> a >> d >> k;

            maxi(maxR[d][a], a + d * k);
        }

        FOR(d, 1, 10)
        {
            memset(used, false, n + 1);
            FOR(i, 1, n) if (maxR[d][i] > i && !used[i])
            {
                int j = i + d;
                int r = maxR[d][i];

                while (j <= r)
                {
                    dsu.Union(j, j - d);
                    maxi(r, maxR[d][j]);
                    used[j] = true;
                    j += d;
                }
            }
        }

        cout << dsu.sets << '\n';
    }

    return 0;
}