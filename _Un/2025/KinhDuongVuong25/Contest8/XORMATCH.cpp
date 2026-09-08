#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree (int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, long long val)
    {
        while (idx <= n)
        {
            bit[idx] ^= val;
            idx += idx & -idx;
        }
    }    

    long long Get(int idx)
    {
        long long res = 0;

        while (idx)
        {
            res ^= bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    void Update(int l, int r, long long val)
    {
        Update(l, val);
        Update(r + 1, val);
    }
};

int const N = 2e5 + 5;

int n, k, q;
long long a[N], b[N];

FenwickTree bit;

int Solve()
{
    bit = FenwickTree(n);
    int res = 0;
    
    FOR(i, 1, n - k + 1)
    {
        long long cur = a[i] ^ bit.Get(i);
        if (cur == b[i]) continue;

        long long x = b[i] ^ cur;
        bit.Update(i, i + k - 1, x);
        res++;
    }

    FOR(i, n - k + 2, n) if ((a[i] ^ bit.Get(i)) != b[i]) return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    cout << Solve() << '\n';

    while (q--)
    {
        char type; 
        int pos;
        long long val;

        cin >> type >> pos >> val;
        if (type == 'a') a[pos] = val;
        else b[pos] = val;

        cout << Solve() << '\n';
    }

    return 0;
}