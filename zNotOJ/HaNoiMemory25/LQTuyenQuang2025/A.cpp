#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

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
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int const N = 1e5 + 5;

int n;
int a[N];

vector<long long> vals = {0};
FenwickTree bit;

long long pre[N];

int GetId(long long x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    
    long long s = 0;
    long long s1 = 0;

    FOR(i, 1, n)
    {
        s += a[i];
        if (i & 1) s1 += a[i];
        vals.push_back(pre[i] = s - 2 * s1);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    bit = FenwickTree(sz(vals));

    int k = GetId(0);
    bit.Update(k, 1); 

    long long res = 0;
   
    FOR(i, 1, n)
    {
        int x = GetId(pre[i]);
        res += bit.Get(x, x);
        bit.Update(x, 1);
    }

    cout << res << '\n';

    return 0;
}