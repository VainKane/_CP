#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n + 1;
        bit.assign(n + 4, 0);
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

    void Reset()
    {
        bit.assign(n + 4, 0);
    }
};

int const N = 1e5 + 5;
int const oo = 1e9;

int n;
long long k;
int a[N];

vector<long long> vals = {0};
FenwickTree bit;

void Init()
{
    bit = FenwickTree(n);

    long long sum = 0;
    FOR(i, 1, n) 
    {
        sum += a[i];
        vals.push_back(sum);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
}

int GetId(long long val)
{
    return lower_bound(all(vals), val) - vals.begin() + 1;
}

long long CountGreater(long long s)
{
    long long curSum = 0;
    long long res = 0;

    bit.Reset();
    bit.Update(GetId(0), 1);

    FOR(i, 1, n)
    {
        curSum += a[i];
        int id = upper_bound(all(vals), curSum - s) - vals.begin();
        res += bit.Get(id);
        bit.Update(GetId(curSum), 1);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    Init();

    long long l = 1ll * -oo * n;
    long long r = 1ll * oo * n;
    long long res;

    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (CountGreater(mid) >= k)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res;

    return 0;
}