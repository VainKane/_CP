#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct FenwickTree
{
    vector<int> bit;
    int n = 0;

    FenwickTree(int _n)
    {   
        n = _n;
        bit.resize(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
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
    
    int Get(int l, int r)
    {
        return Get(r) - Get(l - 1);
    }
};

int const N = 5e4 + 5;
int const X = 

int n, k;
int a[N];

int CountSmaller(int x)
{
    FenwickTree bit(1e6);
    int res = 0;

    FOR(i, 1, n)
    {
        res += bit.Get(a[i] + 1, x + a[i]);
        bit.Update(a[i], 1);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    int l = 1;
    int r = 1e6;
    int res = 0;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (CountSmaller(mid) >= k)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}