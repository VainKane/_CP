#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

int const N = 1e5 + 5;
int const oo = 1e5;
int const NMOD = 4;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    Hash operator + (Hash const other) const
    {
        Hash res;
        REP(k, NMOD) res.x[k] = (x[k] + other.x[k]) % MODS[k];
        return res;
    }  

    Hash operator * (Hash const other) const
    {
        Hash res;

        REP(k, NMOD)
        {
            int a = x[k];
            int b = other.x[k];

            while (b)
            {
                if (b & 1) res.x[k] = (res.x[k] + a) % MODS[k];
                b >>= 1;
                a = 2 * a % MODS[k];
            }
        }

        return res;
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

struct SegmentTree
{
    vector<pair<int, Hash>> t;
    Hash tmp;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        REP(k, NMOD) tmp.x[k] = 1;
        t.assign(4 * n, make_pair(0, tmp));
    }

    pair<int, Hash> MaxPair(pair<int, Hash> a, pair<int, Hash> b)
    {
        if (a.F != b.F) return a.F > b.F ? a : b;
        if (a.F) a.S = a.S + b.S;
        return a;
    }

    void Update(int v, int l, int r, int pos, pair<int, Hash> p)
    {
        if (l == r) 
        {
            t[v] = MaxPair(t[v], p);
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, p);
        else Update(2 * v + 1, mid + 1, r, pos, p);

        t[v] = MaxPair(t[2 * v], t[2 * v + 1]);
    }

    pair<int, Hash> Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return make_pair(0, tmp);
        if (l >= left && r <= right) return t[v];

        int mid = (l + r) >> 1;
        pair<int, Hash> val1 = Get(2 * v, l, mid, left, right);
        pair<int, Hash> val2 = Get(2 * v + 1, mid + 1, r, left, right);

        return MaxPair(val1, val2);
    }

    void Update(int pos, pair<int, Hash> p)
    {
        Update(1, 1, n, pos, p);
    }

    pair<int, Hash> Get(int l, int r)
    {
        if (l < 1 || r > n || l > r) return make_pair(0, tmp);
        return Get(1, 1, n, l, r);
    }
};

int n;
int a[N];

pair<int, Hash> f[N];
pair<int, Hash> g[N];

SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    it = SegmentTree(oo);

    FOR(i, 1, n)
    {
        f[i] = it.Get(1, a[i] - 1);
        f[i].F++;
        it.Update(a[i], f[i]);
    }

    it = SegmentTree(oo);

    FORD(i, n, 1)
    {
        g[i] = it.Get(a[i] + 1, oo);
        g[i].F++;
        it.Update(a[i], g[i]);
    }

    pair<int, Hash> LIS = it.Get(1, oo);

    FOR(i, 1, n)
    {
        if (f[i].F + g[i].F - 1 == LIS.F)
        {
            if (f[i].S * g[i].S == LIS.S) cout << 3;
            else cout << 2;
        }
        else cout << 1;
    }

    return 0; 
}