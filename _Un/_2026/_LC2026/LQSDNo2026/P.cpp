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
int const OS = 1e5 + 1;
int const oo = 1e9 + 9;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, -oo);
    }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) maxi(bit[idx], val); }

    int Get(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) maxi(res, bit[idx]);
        return res;
    }
};

int n;

int a[N], pre[N];
FenwickTree bit;

int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];

    bit = FenwickTree(2 * OS + 5);

    FOR(i, 1, n)
    {
        dp[i] = bit.Get(pre[i] - 1 + OS) + 1;
        if (dp[i] > 0) bit.Update(pre[i] + OS, dp[i]);
    }

    // cout << dp[n];
    FOR(i, 1, n) cout << dp[i] << ' ';

    return 0;
}