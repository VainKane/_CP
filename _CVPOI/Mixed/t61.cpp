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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;

struct FenwickTree
{
    vector<ll> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, ll val) { for (; idx <= n; idx += idx & -idx) maxi(bit[idx], val); }

    ll Get(int idx)
    {
        ll res = 0;
        for (; idx; idx ^= idx & -idx) maxi(res, bit[idx]);
        return res;
    }
};

struct Data
{
    int a, b, h;

    void Input() { cin >> a >> b >> h; }
    bool operator < (Data const other) const
    {
        if (b != other.b) return b > other.b;
        return a > other.a;
    }
};

int n;
Data a[N];
FenwickTree bit;

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n)
    {
        vals.push_back(a[i].a);
        vals.push_back(a[i].b);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    
    FOR(i, 1, n)
    {
        a[i].a = lower_bound(all(vals), a[i].a) - vals.begin() + 1;
        a[i].b = lower_bound(all(vals), a[i].b) - vals.begin() + 1;
    }

    bit = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) a[i].Input();

    sort(a + 1, a + n + 1);
    Compress();

    ll res = 0;
    FOR(i, 1, n)
    {
        ll dp = bit.Get(a[i].b - 1) + a[i].h;
        bit.Update(a[i].a, dp);
        maxi(res, dp);
    }

    cout << res;
    
    return 0;
}