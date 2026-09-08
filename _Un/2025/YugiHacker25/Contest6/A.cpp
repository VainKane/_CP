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
#define name "METRO"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] = (bit[idx] + val) % MOD;
            if (bit[idx] < 0) bit[idx] += MOD;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(l, val);
        Update(r + 1, -val);
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            Add(res, bit[idx]);
            idx ^= idx & -idx;
        }

        return res;
    }
};

int n;
int c[N];
int l[N], r[N];

FenwickTree bit1, bit2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n) 
    {
        cin >> l[i] >> r[i];
        
        l[i] += i;
        r[i] = min(n, i + r[i]);
    }

    bit1 = FenwickTree(n);
    bit2 = FenwickTree(n);

    bit1.Update(1, 1, 1);

    FOR(i, 1, n)
    {
        int cnt = bit1.Get(i);
        int x = (bit2.Get(i) + 1ll * cnt * c[i]) % MOD;

        bit1.Update(l[i], r[i], cnt);
        bit2.Update(l[i], r[i], x);
    }

    cout << bit2.Get(n);

    return 0;
}