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
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

int const N = 2e5 + 5;

int n, q;
int x[N], y[N];
FenwickTree bit;

int pos[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    bit = FenwickTree(q);

    FOR(i, 1, q)
    {
        int type, idx;
        cin >> type >> idx;

        int delta = type == 1 ? 1 : -1;
        int id = type == 1 ? i : pos[idx];
        if (type == 1) pos[idx] = i;

        for (int j = id + x[idx]; j <= q; j += x[idx] + y[idx]) bit.Update(j, min(q, j + y[idx] - 1), delta);
        cout << bit.Get(i) << '\n';
    }

    return 0;
}