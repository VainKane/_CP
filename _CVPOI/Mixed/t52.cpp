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

int const N = 5e5 + 5;
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
        int res = -oo;
        for (; idx; idx ^= idx & -idx) maxi(res, bit[idx]);
        return res;
    }
};

int n;
ll pre[N];

int dp[N], maxDp[N];
FenwickTree bit1, bit2;

vector<ll> vals;

void Compress()
{
    vals.clear();

    FOR(i, 1, n) vals.push_back(pre[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) pre[i] = lower_bound(all(vals), pre[i]) - vals.begin() + 1;
    bit1 = bit2 = FenwickTree(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n)
        {
            int x; cin >> x;
            pre[i] = pre[i - 1] + x;
        }

        Compress();
        memset(maxDp, -0x3f, (n + 1) * sizeof(int));

        FOR(i, 1, n)
        {
            dp[i] = vals[pre[i] - 1] == 0 ? 0 : (vals[pre[i] - 1] > 0 ? i : -i);

            maxi(dp[i], maxDp[pre[i]]);
            maxi(dp[i], bit1.Get(n - pre[i]) - i);
            maxi(dp[i], bit2.Get(pre[i] - 1) + i);

            maxi(maxDp[pre[i]], dp[i]);
            bit1.Update(n - pre[i] + 1, dp[i] + i);
            bit2.Update(pre[i], dp[i] - i);
        }

        cout << dp[n] << '\n';
    }

    return 0;
}