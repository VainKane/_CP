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

struct Query
{
    char type;
    int k, l, r;
};

int const N = 5e5 + 5;

int q;
Query qr[N];

vector<int> vals;
FenwickTree bit;

int GetId(int const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

int GetKth(int k, int left, int right)
{
    int l = left;
    int r = right;
    int res = r;

    if (bit.Get(r) < k) return -1;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (bit.Get(mid) >= k)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("H.inp", "r", stdin);
    // freopen("H.out", "w", stdout);

    cin >> q;
    FOR(i, 1, q)
    {
        char type; cin >> type;
        int k, l = 0, r = 0;

        if (type == '?') cin >> k >> l >> r;
        else 
        {
            cin >> k;
            vals.push_back(k);
        }

        qr[i] = {type, k, l, r};
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    bit = sz(vals);

    FOR(i, 1, q)
    {
        if (qr[i].type == '?')
        {
            int k = qr[i].k;
            int l = GetId(qr[i].l);
            int r = upper_bound(all(vals), qr[i].r) - vals.begin();
        
            int cnt = bit.Get(l - 1);
            int idx = GetKth(cnt + k, 1, r);
            cout << (idx == -1 ? 0 : vals[idx - 1]) << '\n';
        }
        else 
        {
            int k = GetId(qr[i].k);
            if (qr[i].type == '+') bit.Update(k, 1);
            else 
            {
                if (bit.Get(k, k) == 0) continue;
                bit.Update(k, -1);   
            }
        }
    }

    return 0;
}