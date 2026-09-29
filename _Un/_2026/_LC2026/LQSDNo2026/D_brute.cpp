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

int const N = 5009;

int n, m, k;

ll dp[2][N * N];
ll pre[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m)
    {
        ll x; cin >> x;
        pre[i][j] = pre[i][j - 1] + x; 
    }

    bool cur = 1;
    FOR(i, 1, n)
    {
        cur ^= 1;
        memset(dp[cur], 0, k * sizeof(ll));
        FOR(s, 0, m) FORD(j, k, s) maxi(dp[cur][j], dp[cur ^ 1][j - s] + pre[i][s]);
    }

    cout << dp[cur][k];

    return 0;
}