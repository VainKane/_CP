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
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int GetPre(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }

    int GetSuf(int idx)
    {
        return GetPre(n) - GetPre(idx - 1);
    }

    int GetPoint(int idx)
    {
        return GetPre(idx) - GetPre(idx - 1);
    }

    void Reset()
    {
        bit.assign(n + 5, 0);
    }
};

int const N = 3e5 + 5;

int n;
int a[N];

int lowerL[N], lowerR[N];
int greaterL[N], greaterR[N];
int equalL[N], equalR[N];

FenwickTree bit;

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    bit = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Compress();

    FOR(i, 1, n)
    {
        lowerL[i] = bit.GetPre(a[i]);
        greaterL[i] = bit.GetSuf(a[i]);
        equalL[i] = bit.GetPoint(a[i]);
        bit.Update(a[i], 1);
    }

    bit.Reset();

    FORD(i, n, 1)
    {
        lowerR[i] = bit.GetPre(a[i]);
        greaterR[i] = bit.GetSuf(a[i]);
        equalR[i] = bit.GetPoint(a[i]);
        bit.Update(a[i], 1);
    }

    long long res = 0;

    FOR(i, 1, n)
    {
        res += 1LL * lowerL[i] * lowerR[i];
        res += 1LL * greaterL[i] * greaterR[i];
        res -= 1LL * equalL[i] * equalR[i];
    }

    cout << res;

    return 0;
}