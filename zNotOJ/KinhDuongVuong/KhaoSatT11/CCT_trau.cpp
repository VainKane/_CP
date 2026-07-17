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
#define name "CCT"

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

    int GetRank(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return n - res + 1;
    }
};

int const N = 5e4 + 5;

int n, m, q;
int a[N];

namespace Sub1
{
    bool CheckSub()
    {
        return true;
    }

    int b[N];

    void Solve()
    {
        while (q--)
        {
            int idx, val;
            cin >> idx >> val;

            a[idx] = val;
            FOR(i, 1, n) b[i] = a[i];

            sort(b + 1, b + n + 1, greater<int> ());

            int j = 1;
            int cnt = 0;
            long long res = 0;

            FOR(i, 1, n)
            {
                if (++cnt > m)
                {
                    cnt = 1;
                    j++;
                }
                res += 1LL * j * b[i];
            }

            cout << res << '\n';
        }
    }
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    cin >> q;

    if (Sub1::CheckSub()) return Sub1::Solve(), 0;

    return 0;
}
