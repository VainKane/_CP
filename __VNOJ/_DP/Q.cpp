#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.resize(n + 5);
    }

    void Update(int idx, long long val)
    {
        while (idx <= n)
        {
            maxi(bit[idx], val);
            idx += idx & -idx;
        }
    }

    long long GetMax(int idx)
    {
        long long res = 0;
        
        while (idx)
        {
            maxi(res, bit[idx]);
            idx ^= idx & -idx;
        }

        return res;
    }
};

int const N = 2e5 + 5;

int n;
int h[N], a[N];

long long f[N];
FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, n) cin >> a[i];

    bit = FenwickTree(n);

    FOR(i, 1, n) bit.Update(h[i], bit.GetMax(h[i] - 1) + a[i]);
    cout << bit.GetMax(n);
    
    return 0;
}