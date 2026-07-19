#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))
#define all(v) v.begin(), v.end()
#define name "coprime"

int const N = 1e5 + 5;
int const primes[5] = {2, 3, 5, 7, 11};

int n;
long long a[N];

vector<long long> values;
int divMask[N];

int dp[N];

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
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int Get(int idx)
    {
        int res = 0;
        while (idx)
        {
            res = max(res, bit[idx]);
            idx ^= idx & -idx;
        }
        return res;
    }
};

void Init()
{
    FOR(i, 1, n) 
    {
        REP(j, 5) if (a[i] % primes[j] == 0) divMask[i] |= MK(j);
        values.push_back(a[i]);
    }
   
    sort(all(values));
    values.erase(unique(all(values)), values.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FenwickTree bit[MK(5)];
    REP(mask, MK(5)) bit[mask] = FenwickTree(n);

    Init();

    FOR(i, 1, n)
    {
        int pos = lower_bound(all(values), a[i]) - values.begin() + 1;

        REP(mask, MK(5)) if ((divMask[i] & mask) == 0)
            dp[i] = max(dp[i], bit[mask].Get(pos - 1) + 1);

        bit[divMask[i]].Update(pos, dp[i]);
    }

    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}