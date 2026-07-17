#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
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

int const N = 2e5 + 5;

int n;
pair<int, int> a[N];

FenwickTree bit;

int id[N];
int res[N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n)
    {
        vals.push_back(a[i].F);
        vals.push_back(a[i].S);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        a[i].F = lower_bound(all(vals), a[i].F) - vals.begin() + 1;
        a[i].S = lower_bound(all(vals), a[i].S) - vals.begin() + 1;
    }

    bit = FenwickTree(sz(vals));
}

bool cmp(int i, int j)
{
    if (a[i].S != a[j].S) return a[i].S < a[j].S;
    return a[i].F > a[j].F;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        cin >> a[i].F >> a[i].S;
        id[i] = i;
    }

    Compress();
    sort(id + 1, id + n + 1, cmp);

    FOR(i, 1, n)
    {
        res[id[i]] = bit.Get(a[id[i]].F);
        bit.Update(a[id[i]].F, 1);
    }

    FOR(i, 1, n) cout << res[i] << '\n';

    return 0;
}