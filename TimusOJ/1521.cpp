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

int const LOG = 21;

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

    int Search(int val)
    {
        int pos = 0;
        int s = 0;

        FORD(i, LOG, 0) if (pos + MK(i) <= n && s + bit[pos | MK(i)] < val)
            s += bit[pos |= MK(i)];

        return pos + 1;
    }
};

int n, k;
FenwickTree bit;

int pos;

void Jump(int x)
{
    int y = bit.Get(n) - bit.Get(pos) + 1;

    if (x < y) pos = bit.Search(bit.Get(pos) + x);
    else pos = bit.Search(x - y + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    bit = FenwickTree(n);
    pos = k;

    FOR(i, 1, n) if (i != k) bit.Update(i, 1);

    cout << pos << ' ';

    FOR(i, 1, n - 1)
    {
        Jump(1);
        Jump((k - 1) % (n - i));
        
        bit.Update(pos, -1);
        cout << pos << ' ';
    }

    return 0;
}