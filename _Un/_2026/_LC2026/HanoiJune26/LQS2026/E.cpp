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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;

struct DSU
{
    vector<int> par, sz;
    vector<int> mi, ma;
    int n;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            mi[i] = ma[i] = par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par = sz = mi = ma = vector<int>(n + 5, 0);
        MakeSet();
    }

    int Find(int v) { return par[v] == v ? v : par[v] = Find(par[v]); }
    bool Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);
        
        mini(mi[a], mi[b]), maxi(ma[a], ma[b]);
        sz[a] += sz[b];
        par[b] = a;

        return true;
    }
};

int n, q;
DSU up[20];

void Update(int l, int r, int k)
{
    if (r > n) return;
    if (!up[k].Union(l, r) || !k) return;
    
    Update(l, r, k - 1);
    Update(l + MK(k - 1), r + MK(k - 1), k - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 0, 31 - __builtin_clz(n)) up[i] = DSU(n);

    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int u; cin >> u;
            u = up[0].Find(u);
            cout << up[0].mi[u] << ' ' << up[0].ma[u] << '\n';
        }
        else
        {
            int l, r, len;
            cin >> l >> r >> len;

            for (int tmp = len; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp);
                Update(l, r, i);
                l += MK(i), r += MK(i);
            }
        }
    }

    return 0;
}