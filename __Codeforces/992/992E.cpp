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
    vector<long long> bit;
    int n, LOG;

    FenwickTree(int _n = 0)
    {
        n = _n;
        LOG = 31 - __builtin_clz(n);
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

    long long Get(int idx)
    {
        long long res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    int Search(long long val)
    {
        int pos = 0;
        long long s = 0;

        FORD(i, LOG, 0) if ((pos | MK(i)) <= n && s + bit[pos | MK(i)] < val)
            s += bit[pos |= MK(i)];

        return pos + 1;
    }

    int Query()
    {
        int pos = 1;

        while (true)
        {
            int nxt = Search(2 * Get(pos));
            if (nxt > n) break;

            if (Get(nxt) == 2 * Get(nxt - 1)) return nxt;
            pos = nxt;
        }

        return -1;
    }
};

int const N = 2e5 + 5;

int n, q;
int a[N];

FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;

    bit = FenwickTree(n);

    FOR(i, 1, n)
    {
        cin >> a[i];
        bit.Update(i, a[i]);
    }

    while (q--)
    {
        int pos, val;
        cin >> pos >> val;

        bit.Update(pos, val - a[pos]);
        a[pos] = val;

        cout << bit.Query() << '\n';
    }

    return 0;
}