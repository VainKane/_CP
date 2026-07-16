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

struct FenwickTree
{
    vector<pair<int, Hash>> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, make_pair(0, Hash()));
    }

    void Update(int idx, pair<int, Hash> p)
    {
        while (idx <= n)
        {
            if (bit[idx].F < p.F) bit[idx] = p;
            else if (bit[idx].F == p.F) bit[idx].S = bit[idx].S + p.S;
            idx += idx & -idx;
        }
    }   

    pair<int, Hash> Get(int idx)
    {
        pair<int, Hash> res;
        res.F = 0;
        REP(k, NMOD) res.S.x[k] = 1;

        while (idx)
        {
            if (bit[idx].F > res.F) res = bit[idx];
            else if (bit[idx].F == res.F) res.S = res.S + bit[idx].S;
            idx ^= idx & -idx;
        }

        return res;
    }
};

struct RevFenwickTree
{
    vector<pair<int, Hash>> bit;
    int n;

    RevFenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, make_pair(0, Hash()));
    }

    void Update(int idx, pair<int, Hash> p)
    {
        while (idx)
        {
            if (bit[idx].F < p.F) bit[idx] = p;
            else if (bit[idx].F == p.F) bit[idx].S = bit[idx].S + p.S;
            idx ^= idx & -idx;
        }
    }   

    pair<int, Hash> Get(int idx)
    {
        pair<int, Hash> res;
        res.F = 0;
        REP(k, NMOD) res.S.x[k] = 1;

        while (idx <= n)
        {
            if (bit[idx].F > res.F) res = bit[idx];
            else if (bit[idx].F == res.F) res.S = res.S + bit[idx].S;
            idx += idx & -idx;
        }

        return res;
    }
};

int n;
int a[N];

pair<int, Hash> f[N];
pair<int, Hash> g[N];

FenwickTree bit1;
RevFenwickTree bit2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    bit1 = FenwickTree(oo);
    bit2 = RevFenwickTree(oo);

    FOR(i, 1, n)
    {
        f[i] = bit1.Get(a[i] - 1);
        f[i].F++;
        bit1.Update(a[i], f[i]);
    }

    FORD(i, n, 1)
    {
        g[i] = bit2.Get(a[i] + 1);
        g[i].F++;
        bit2.Update(a[i], g[i]);
    }

    pair<int, Hash> LIS = bit1.Get(oo);

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