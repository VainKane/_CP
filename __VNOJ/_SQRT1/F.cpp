#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
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

int const N = 2.5e5;
int const BK = 2000;
int const oo = 5e4;
int bkId[N];

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = oo + 5)
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

int n, m;

int a[N];
pair<int, int> qr[N];

vector<int> vals[BK + 5];
FenwickTree bit[BK + 5];

long long res = 0;

void Init()
{
    FenwickTree haha;

    FORD(i, n - 1, 0)
    {
        bkId[i] = i / BK;
        bit[bkId[i]].Update(a[i] + 1, 1);

        res += haha.Get(a[i]);
        haha.Update(a[i] + 1, 1);
    }
}

long long Get(int l, int r, int u, int v)
{
    if (l > r) return 0;
    long long res = 0;

    if (bkId[l] == bkId[r])
    {
        FOR(i, l, r) res += a[i] >= u && a[i] <= v;
        return res;
    }
    
    FOR(i, bkId[l] + 1, bkId[r] - 1) res += bit[i].Get(u + 1, v + 1);
    FOR(i, l, BK * (bkId[l] + 1) - 1) res += a[i] >= u && a[i] <= v;
    FOR(i, BK * bkId[r], r) res += a[i] >= u && a[i] <= v;
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> a[i];
    
    Init();
        
    cin >> m;
    while (m--)
    {
        int idx, val;
        cin >> idx >> val;
        idx--;

        res -= Get(0, idx - 1, a[idx] + 1, oo);
        res -= Get(idx + 1, n - 1, 1, a[idx] - 1);
        bit[bkId[idx]].Update(a[idx] + 1, -1);

        a[idx] = val;

        res += Get(0, idx - 1, a[idx] + 1, oo);
        res += Get(idx + 1, n - 1, 1, a[idx] - 1);
        bit[bkId[idx]].Update(a[idx] + 1, 1);

        cout << res << '\n';
    }

    return 0;
}