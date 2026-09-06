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
    vector<int> bit;
    int n;
    
    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx; idx ^= idx & -idx) bit[idx] += val; }

    int Get(int idx)
    {
        int res = 0;
        for (; idx <= n; idx += idx & -idx) res += bit[idx];
        return res;
    }
};

int n;

ii a[N];
FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F, a[i].S = i;

    sort(a + 1, a + n + 1);
    bit = FenwickTree(n);

    int res = 1;
    FOR(i, 1, n)
    {
        maxi(res, bit.Get(i));
        bit.Update(a[i].S, 1);
    }

    cout << res;

    return 0;
}