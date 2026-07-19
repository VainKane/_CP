#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree (int _n = 0)
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

    long long Get(int idx)
    {
        long long res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

struct FenwickTreeMod
{
    vector<int> bit;
    int n;

    FenwickTreeMod (int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] = (1ll * bit[idx] + val + MOD) % MOD;
            idx += idx & -idx;
        }
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            Add(res, bit[idx]);
            idx ^= idx & -idx;
        }

        return res;
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        
        int tmp = Get(r) - Get(l - 1);
        if (tmp < 0) tmp += MOD;
        return tmp;
    }
};


int n, q;
int a[N], w[N];

FenwickTree bitS;
FenwickTreeMod bitP;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    bitS = FenwickTree(n);
    bitP = FenwickTreeMod(n);

    FOR(i, 1, n) 
    {
        cin >> a[i];
        a[i] -= i;
    }
    FOR(i, 1, n) 
    {
        cin >> w[i];
        bitS.Update(i, w[i]);
        bitP.Update(i, 1ll * a[i] * w[i] % MOD);
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        
        if (x < 0) 
        {
            x = -x;

            bitS.Update(x, -w[x]);
            bitS.Update(x, y);
            bitP.Update(x, -1ll * w[x] * a[x] % MOD);
            bitP.Update(x, 1ll * y * a[x] % MOD);

            w[x] = y;
        }
        else
        {
            int l = x;
            int r = y;
            int med = r;

            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (bitS.Get(x, mid) >= (bitS.Get(x, y) + 1) / 2)
                {
                    med = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            int res = 0;
            
            Add(res, 1ll * a[med] * (bitS.Get(x, med) % MOD) % MOD);
            Sub(res, bitP.Get(x, med));
            
            Add(res, bitP.Get(med, y));
            Sub(res, 1ll * a[med] * (bitS.Get(med, y) % MOD) % MOD);

            cout << res << '\n';
        }
    }

    return 0;
}