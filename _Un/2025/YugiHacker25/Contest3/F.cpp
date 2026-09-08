#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "nearest"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct FenwickTree
{
    vector<int> bit;
    int n, oo;

    FenwickTree(int _n = 0)
    {
        n = _n;
        oo = n + 5;
        bit.assign(n + 5, oo);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            mini(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int GetMin(int idx)
    {
        int res = oo;
        
        while (idx)
        {
            mini(res, bit[idx]);
            idx ^= idx & -idx;
        }

        if (res == oo) res = -1;
        return res;
    }
};

int const N = 5e5 + 5;

int n, q;
int a[N];
vector<pair<int, int>> qr[N];

int last[N], nxt[N];
int res[N];

FenwickTree bit;

void Init()
{
    vector<int> vals;
    
    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;

    memset(last, 0x3f, sizeof last);
    FORD(i, n, 1)
    {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    bit = FenwickTree(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        qr[l].push_back({r, i});
    }

    Init();

    FORD(i, n, 1)
    {
        bit.Update(nxt[i], nxt[i] - i);
        for (auto &p : qr[i]) res[p.S] = bit.GetMin(p.F);
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}