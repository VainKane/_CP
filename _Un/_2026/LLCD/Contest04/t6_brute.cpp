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
int const oo = 2e9 + 9;

struct Data
{
    int l, r, p;
    void Input() { cin >> l >> r >> p; }
    bool operator < (Data const other) { return r < other.r; }
};

int n, m;
Data a[N];

int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) a[i].Input();

    sort(a + 1, a + n + 1);

    int res = oo;
    FOR(i, 1, n)
    {
        dp[i] = oo;
        FORD(j, i - 1, 0)
        {
            if (a[j].r < a[i].l - 1) break;
            mini(dp[i], max(dp[j], a[i].p + (a[j].r >= a[i].l) * dp[j]));
        }

        if (a[i].r == m) mini(res, dp[i]);
        cout << dp[i] << ' ';
    }

    // cout << (res != oo ? res : -1);

    return 0;
}