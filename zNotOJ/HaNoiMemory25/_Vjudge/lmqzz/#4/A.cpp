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
        if (l < 1 || r > n || l > r) return;
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

int const N = 1e4 + 5;
int const os = 1e6 + 1;

int n, k;

pair<int, int> a[N];
FenwickTree bit(2e6 + 1);

bool used[N];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n)
    {
        int l, r;
        cin >> l >> r;
        a[i] = {l + os, r + os};
    }

    sort(a + 1, a + n + 1);

    FOR(haha, 1, k)
    {
        int ma = 0, pos = 0;

        FOR(i, 1, n) if (!used[i])
        {
            bit.Update(a[i].F, a[i].S, 1);
            if (maxi(ma, bit.Get(a[i].F))) pos = a[i].F;
            if (maxi(ma, bit.Get(a[i].S))) pos = a[i].S;
        }

        if (pos == 0) break;

        if (haha == 1) cout << "debug: " << ma << ' ' << pos - os << '\n';

        FOR(i, 1, n) if (!used[i])
        {
            if (a[i].F <= pos && a[i].S >= pos) used[i] = true;
            bit.Update(a[i].F, a[i].S, -1);
        } 
    }

    int res = 0;
    FOR(i, 1, n) res += used[i];
    cout << res;

    return 0;
}