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
        while (idx)
        {
            bit[idx] += val;
            idx ^= idx & -idx;
        }
    }

    int GetRank(int idx)
    {
        int res = 0;

        while (idx <= n)
        {
            res += bit[idx];
            idx += idx & -idx;
        }

        return res;
    }
};

int const N = 5e4 + 5;

int n, m, q;
int a[N];

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 1000 && q <= 1000;
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

namespace Sub5
{
    pair<int, int> qr[N];
    vector<int> vals;

    FenwickTree bit;

    bool CheckSub()
    {
        return true;
    }

    int GetId(int x)
    {
        return lower_bound(all(vals), x) - vals.begin() + 1;
    }

    int GetGroup(int rk)
    {
        if (rk % m == 0) return rk / m;
        return rk / m + 1;
    }

    void Compress()
    {
        FOR(i, 1, n) vals.push_back(a[i]);
        FOR(i, 1, q) vals.push_back(qr[i].S);

        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());

        FOR(i, 1, n) a[i] = GetId(a[i]);
        FOR(i, 1, q)
        {
            qr[i].F = GetId(qr[i].F);
            qr[i].S = GetId(qr[i].S);
        }

       bit = FenwickTree(sz(vals));
    }

    void Solve()
    {
        FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;
        Compress();

        FOR(i, 1, n) bit.Update(a[i], 1);

        long long res = 0;
        FOR(i, 1, n) res += 1LL * vals[a[i] - 1] * GetGroup(bit.GetRank(a[i]));

        FOR(i, 1, q)
        {
            int idx = qr[i].F;
            int val = qr[i].S;

            int oldRank = bit.GetRank(a[idx]);
            // cout << idx << ' ' << val;

            res -= 1LL * vals[a[idx] - 1] * GetGroup(oldRank);
            bit.Update(a[idx], -1);
            
            a[idx] = GetId(val);

            bit.Update(a[idx], 1);
            int newRank = bit.GetRank(a[idx]);
            res += 1LL * val * GetGroup(newRank);

            if (i == 1) cout << oldRank << ' ';

            cout << res << '\n';
        }
    }
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    cin >> q;

    if (Sub5::CheckSub()) return Sub5::Solve(), 0;

    return 0;
}
