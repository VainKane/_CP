#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()

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

    void Update(int idx, int val)
    {
        while (idx)
        {
            maxi(bit[idx], val);
            idx ^= idx & -idx;          
        }
    }

    int GetMax(int idx)
    {
        int res = 0;

        while (idx <= n)
        {
            maxi(res, bit[idx]);
            idx += idx & -idx;
        }

        return res;
    }
};

int const N = 3e4 + 5;

int n;
int a[N];

FenwickTree bit;

void Init()
{
    bit = FenwickTree(n);
    vector<int> values;

    FOR(i, 1, n) values.push_back(a[i]);
    sort(all(values));
    values.erase(unique(all(values)), values.end());

    FOR(i, 1, n) a[i] = lower_bound(all(values), a[i]) - values. begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    FORD(i, n, 1) bit.Update(a[i], bit.GetMax(a[i] + 1) + 1);
    cout << bit.GetMax(1);

    return 0;
}