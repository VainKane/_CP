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
    vector<pair<int, int>> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, {0, 1});
    }

    void Update(int idx, pair<int, int> p)
    {
        while (idx <= n)
        {
            mini(bit[idx], p);
            idx += idx & -idx;
        }
    }

    pair<int, int> Get(int idx)
    {
        pair<int, int> res = {1e9, n};
        
        while (idx)
        {
            mini(res, bit[idx]);
            idx ^= idx & -idx;
        }

        return res;
    }
};

int n, q;
FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;

    bit = FenwickTree(n);
    while (q--)
    {
        int r, p;
        cin >> r >> p;
        
        auto val = bit.Get()   
    }

    return 0;
}