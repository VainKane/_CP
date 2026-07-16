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

int const N = 2e5 + 5;
int const LOG = 19;

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

    int Search(int val)
    {
        int pos = 0;
        int s = 0;

        FORD(i, LOG, 0) if (pos + MK(i) <= n && s + bit[pos + MK(i)] < val) 
            s += bit[pos |= MK(i)];

        return pos + 1;
    }
};

int n;
int a[N];

FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    bit = FenwickTree(n);
    FOR(i, 1, n) bit.Update(i, 1);

    FOR(i, 1, n)
    {
        int pos; cin >> pos;
        pos = bit.Search(pos);

        bit.Update(pos, -1);
        cout << a[pos] << ' ';
    }

    return 0;
}