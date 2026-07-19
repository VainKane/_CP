#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define name "CAU5"

int const N = 2e5 + 5;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
       n = _n;
       bit.resize(n + 5);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            Add(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int GetSum(int idx)
    {
        int res = 0;

        while (idx)
        {
             Add(res, bit[idx]);
             idx ^= idx & -idx;
        }

        return res;
    }
};

int n;
int a[N];
vector<int> values;

FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], values.push_back(a[i]);

    bit = FenwickTree(n);
    sort(all(values));
    FOR(i, 1, n) a[i] = lower_bound(all(values), a[i]) - values.begin() + 1;

    FOR(i, 1, n)
    {
        int val = (bit.GetSum(a[i] - 1) + 1) % MOD;
        bit.Update(a[i], val);
    }

    cout << bit.GetSum(n);

    return 0;
}
