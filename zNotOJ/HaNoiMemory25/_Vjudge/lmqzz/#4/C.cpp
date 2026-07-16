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
#define name "help"

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
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;

pair<int, int> a[N];
FenwickTree bit;

int pw[N];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.S < b.S;
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".in", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    pw[0] = 1;
    FOR(i, 1, n) pw[i] = 2 * pw[i - 1] % MOD;

    sort(a + 1, a + n + 1);
    bit = FenwickTree(2 * n);

    int res = 0;

    FOR(i, 1, n)
    {
        bit.Update(a[i].S, 1);
        Add(res, pw[n - bit.Get(a[i].F, bit.n)]);
    }

    cout << res;

    return 0;
}