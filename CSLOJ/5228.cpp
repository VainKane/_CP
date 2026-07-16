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
        n = _n;
        bit.assign(n + 4, 0);
    }

    void Update(int idx, int val)
    {
        while (idx)
        {
            bit[idx] += val;
            idx ^= idx & -idx;
        }
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx <= n)
        {
            res += bit[idx];
            idx += idx & -idx;
        }

        return res;
    }
};

struct Data
{
    int l, r, i;

    bool operator < (Data const other) const
    {
        if (l != other.l) return l < other.l;
        return r > other.r;
    }
};

int const N = 2e5 + 5;

int n;
Data a[N];
FenwickTree bit;

map<pair<int, int>, int> mp;
int res[N];

void Compress()
{
    vector<int> vals;
    FOR(i, 1, n) vals.push_back(a[i].r);

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i].r = lower_bound(all(vals), a[i].r) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r, i};
    }

    sort(a + 1, a + n + 1);
    Compress();
    bit = FenwickTree(n);

    FOR(i, 1, n)
    {
        mp[{a[i].l, a[i].r}] = bit.Get(a[i].r);
        bit.Update(a[i].r, 1);
    }

    FOR(idx, 1, n)
    {
        int i = a[idx].i;
        res[i] = mp[{a[idx].l, a[idx].r}];
    }

    FOR(i, 1, n) cout << res[i] << ' ';

    return 0;
}