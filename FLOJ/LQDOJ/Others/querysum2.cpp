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
    vector<long long> bit1, bit2;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit1.assign(n + 5, 0);
        bit2.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        for (int i = idx; i <= n; i += i & -i)
        {
            bit1[i] += 1LL * val * (n - idx + 1);
            bit2[i] += val;
        }
    }

    void Update(int l, int r, int val)
    {
        Update(l, val);
        Update(r + 1, -val);
    }

    long long Get(int idx)
    {
        long long res = 0;

        for (int i = idx; i; i ^= i & -i)
            res += bit1[i] - 1LL * (n - idx) * bit2[i];

        return res;
    }

    long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int const N = 2e5 + 5;

int n, q;
FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    bit = FenwickTree(n);

    FOR(i, 1, n) 
    {
        int x; cin >> x;
        bit.Update(i, i, x);
    }

    while (q--)
    {
        int type, a, b, x;
        cin >> type >> a >> b;

        if (type == 1)
        {
            cin >> x;
            bit.Update(a, b, x);
        }
        else cout << bit.Get(a, b) << '\n';
    }

    return 0;
}