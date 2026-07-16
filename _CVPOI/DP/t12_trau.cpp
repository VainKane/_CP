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

int const N = 1009;

int n, k;
int s[N], t[N], c[N];
vector<int> vals;

void Compress()
{
    FOR(i, 1, n)
    {
        vals.push_back(s[i]);
        vals.push_back(t[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        s[i] = lower_bound(all(vals), s[i]) - vals.begin() + 1;
        t[i] = lower_bound(all(vals), t[i]) - vals.begin() + 1;
    }
}

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 20;
    }

    FenwickTree bit(sz(vals));

    int Check(int mask)
    {
        int res = 0;

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            bit.Update(s[i + 1], t[i + 1], 1);
            res += c[i + 1];
        }

        int ma = 0;
        FOR(i, 1, sz(vals)) maxi(ma, bit.Get(i));

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            bit.Update(s[i + 1], t[i + 1], -1);
        }

        return ma <= k ? res : 0;
    }

    void Process()
    {
        bit = FenwickTree(sz(vals));

        int res = 0;
        REP(mask, MK(n)) maxi(res, Check(mask));
        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) 
    {
        cin >> s[i] >> t[i] >> c[i];
        t[i] += s[i] - 1;
    }

    Compress();

    if (Sub1::CheckSub()) Sub1::Process(), 0;

    return 0;
}