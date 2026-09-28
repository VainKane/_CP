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

int const N = 1009;
int const M = 1e5 + 5;
int const MOD = 998244353;

int n, k;
int a[N];

int dp[N][N];
int pos[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);
    
    FOR(i, 0, 1e5)
    {
        if (i) pos[i] = pos[i - 1];
        while (pos[i] < n && a[pos[i] + 1] <= i) pos[i]++;
    }

    int res = 0;
    FOR(t, 1, a[n] / k)
    {
        FOR(i, 1, pos[t]) dp[0][i] = 1;
        FOR(j, 1, k)
        {
            FOR(i, 2, n) if (a[i] - t >= 0)
            {
                dp[j][i] = (dp[j][i - 1] + dp[j - 1][pos[a[i] - t]]) % MOD;
            }
        }

        res = (res + 1LL * t * dp[k][n]) % MOD;
    }

    cout << res;

    return 0;
}