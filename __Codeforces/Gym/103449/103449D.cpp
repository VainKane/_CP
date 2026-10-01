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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
int const oo = 1e9 + 9;

struct FenwickTree
{
    vector<vector<int>> bit, vals;
    int m;

    FenwickTree(int _m = 0)
    {
        m = _m;
        bit = vals = vector<vector<int>>(m + 5, vector<int>());    
    }

    void FakeUpdate(int i, int j) { for (; i <= m; i += i & -i) vals[i].push_back(j); }
    void FakeGet(int i, int j) { for (; i; i ^= i & -i) vals[i].push_back(j); }

    void FakeGet(int t, int b, int l, int r)
    {
        if (t > b || l > r) return;
        FakeGet(b, r); FakeGet(t - 1, r); FakeGet(b, l - 1); FakeGet(t - 1, l - 1);
    }

    void Compress()
    {
        FOR(i, 1, m)
        {
            sort(all(vals[i]));
            vals[i].erase(unique(all(vals[i])), vals[i].end());
            bit[i] = vector<int>(sz(vals[i]) + 5, 0);
        }
    }

    #define GetId(i, x) (lower_bound(all(vals[i]), (x)) - vals[i].begin() + 1)

    void Update(int i, int jj, int val)
    {
        for (; i <= m; i += i & -i) for (int j = GetId(i, jj); j <= sz(vals[i]); j += j & -j)
            bit[i][j] += val;
    }

    int Get(int i, int jj)
    {
        int res = 0;

        for (; i; i ^= i & -i) for (int j = GetId(i, jj); j; j ^= j & -j)
            res += bit[i][j];

        return res;
    }

    int Get(int t, int b, int l, int r)
    {
        if (t > b || l > r) return 0;
        return Get(b, r) - Get(t - 1, r) - Get(b, l - 1) + Get(t - 1, l - 1);
    }
};

int n, q;

int a[N];
ii qr[N];

FenwickTree bit;
ll res = 0;

void Solve(bool prepare)
{
    FORD(i, n, 1)
    {
        if (prepare)
        {
            bit.FakeUpdate(i, a[i]);
            bit.FakeGet(i + 1, n, 1, a[i] - 1);
        }
        else
        {
            bit.Update(i, a[i], 1);
            res += bit.Get(i + 1, n, 1, a[i] - 1);
        }
    }

    FOR(i, 1, q)
    {
        if (prepare)
        {
            int idx = qr[i].F;
            bit.FakeGet(1, idx - 1, a[idx] + 1, oo);
            bit.FakeGet(idx + 1, n, 1, a[idx] - 1);

            bit.FakeUpdate(idx, a[idx]);
            bit.FakeUpdate(idx, qr[i].S);

            bit.FakeGet(1, idx - 1, qr[i].S + 1, oo);
            bit.FakeGet(idx + 1, n, 1, qr[i].S - 1);
        }
        else
        {
            int idx = qr[i].F;
            res -= bit.Get(1, idx - 1, a[idx] + 1, oo);
            res -= bit.Get(idx + 1, n, 1, a[idx] - 1);

            bit.Update(idx, a[idx], -1);
            a[idx] = qr[i].S;
            bit.Update(idx, a[idx], 1);

            res += bit.Get(1, idx - 1, a[idx] + 1, oo);
            res += bit.Get(idx + 1, n, 1, a[idx] - 1);

            cout << res << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;

    bit = FenwickTree(n);
    Solve(true);

    bit.Compress();
    Solve(false);

    return 0;
}