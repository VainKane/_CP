#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= a; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
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

    void UpdatePre(int idx, int val)
    {
        while (idx <= n)
        {
            maxi(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int GetPre(int idx)
    {
        int res = 0;

        while (idx)
        {
            maxi(res, bit[idx]);
            idx ^= idx & -idx;
        }

        return res;
    }

    void UpdateSuf(int idx, int val)
    {
        while (idx)
        {
            maxi(bit[idx], val);
            idx ^= idx & -idx;
        }
    }

    int GetSuf(int idx)
    {
        int res = 0;

        while (idx <= n)
        {
            maxi(res, bit[idx]);
            idx += idx & -idx;
        }

        return res;
    }

    void Reset()
    {
        bit.assign(n + 5, 0);
    }
};

int const N = 2e5 + 5;

int n, d;

int a[N];
int g[N];

int idx[N];

FenwickTree bit;
vector<int> vals;

int GetId(int const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Init()
{
    FOR(i, 1, n)
    {
        vals.push_back(a[i]);
        vals.push_back(a[i] + d);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) idx[i] = GetId(a[i]);

    bit = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];

    Init();

    FORD(i, n, 1)
    {
        g[i] = bit.GetSuf(idx[i] + 1) + 1;
        bit.UpdateSuf(idx[i], g[i]);
    }

    bit.Reset();

    int res = 0;
    FOR(i, 1, n)
    {
        int x = bit.GetPre(GetId(a[i] + d) - 1);
        maxi(res, g[i] + x);
        bit.UpdatePre(idx[i], bit.GetPre(idx[i] - 1) + 1);
    }

    cout << res;

    return 0;
}