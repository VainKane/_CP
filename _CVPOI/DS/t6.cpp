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

struct Data
{
    int l, r, sz;

    bool operator < (Data const other) const
    {
        return r < other.r;
    }
};

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
int inv[N];

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int res = 1;
    FOR(i, 1, n) inv[i] = PowMod(i, MOD - 2);

    set<Data> s;
    FOR(i, 1, n)
    {
        int l, r, sz = 1;
        cin >> l >> r;

        if (!s.empty())
        {
            auto it = s.lower_bound({0, l, 0});
            while (it != s.end() && it->l <= r && it->r >= l)
            {
                res = 1LL * res * inv[it->sz] % MOD;
                sz += it->sz;

                mini(l, it->l);
                maxi(r, it->r);

                s.erase(it++);
            }
        }

        res = 1LL * res * sz % MOD;
        s.insert({l, r, sz});

        cout << res << '\n';
    }

    return 0;
}