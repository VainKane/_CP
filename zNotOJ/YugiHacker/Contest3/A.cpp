#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.F != b.F) return a.F < b.F;
    return a.S > b.S;
}

int const N = 2e5 + 5;

int n;
pair<int, int> a[N];

FenwickTree bit;
vector<int> vals;    

int GetId(int const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Init()
{
    FOR(i, 1, n) 
    {
        vals.push_back(a[i].F);
        vals.push_back(a[i].S);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) 
    {
        a[i].F = GetId(a[i].F);
        a[i].S = GetId(a[i].S);
    }
    
    sort(a + 1, a + n + 1, cmp);
    bit = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    Init();

    int res = 1;

    FOR(i, 1, n)
    {
        bit.Update(a[i].S, 1);
        maxi(res, bit.Get(a[i].F));
    }

    cout << res;

    return 0;
}