#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "srednji"

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree (int _n = 0)
    {
        n = _n;
        bit.resize(n + 5);
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
        
        while (idx > 0)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

int const N = 3e5 + 5;

int n, med;
int a[N];

long long Get(int x)
{
    FenwickTree bit(2 * n + 1);

    long long res = 0;
    int sum = n + 1;

    bit.Update(n + 1, 1);

    FOR(i, 1, n)
    {
        sum += a[i] <= x ? 1 : -1;
        res += bit.Get(sum);
        bit.Update(sum, 1);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int sub; cin >> sub;
    cin >> n >> med;
    FOR(i, 1, n) cin >> a[i];

    cout << Get(med) - Get(med - 1);
    
    return 0;
}