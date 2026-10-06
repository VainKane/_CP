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

int const N = 2009;

int n, k;
int a[N];

int dp[N][N];

bool Check(int x)
{
    memset(dp, 0x3f, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);

    FOR(i, 1, n) FOR(j, 0, 300) FOR(k, max(0, j - x), min(300, j + x)) mini(dp[i][j], dp[i - 1][k] + (a[i] != j));
    return *min_element(dp[n] + 0, dp[n] + 301) <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    int l = 0, r = 300;
    int res = r;

    while (l <= r)
    {
        int mid = l + r >> 1;
        if (Check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << res;

    return 0;
}