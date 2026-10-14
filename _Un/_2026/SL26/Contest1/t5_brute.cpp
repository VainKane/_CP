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

int const N = 509;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n;
int a[N], b[N];
int preA[N], preB[N];

int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], preA[i] = preA[i - 1] + a[i];
    FOR(i, 1, n) cin >> b[i], preB[i] = preB[i - 1] + b[i];

    dp[0][0] = 1;
    FOR(i, 1, n) FOR(j, 1, n) REP(p, i) REP(q, j)
    {
        if (1LL * (preA[i] - preA[p]) * (j - q) > 1LL * (preB[j] - preB[q]) * (i - p)) continue;
        Add(dp[i][j], dp[p][q]);
    }

    cout << dp[n][n];

    return 0;
}