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

int const N = 1e6 + 5;
int MOD;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;

int a[N];
int cnt[2 * N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> MOD;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);
    FOR(x, 0, 2 * m)
    {
        memset(dp, 0, (n + 1) * sizeof(int));
        FOR(i, 1, n)
        {
            FOR(j, 1, i - 1) if ((a[i] ^ a[j]) > x) Add(dp[i], dp[j] + 1);
            Add(cnt[x], dp[i]);
        }
    }

    int res = 0;
    FOR(x, 1, 2 * m) res = (res + 1LL * x * (cnt[x - 1] - cnt[x] + MOD)) % MOD;
    cout << res;

    return 0;
}