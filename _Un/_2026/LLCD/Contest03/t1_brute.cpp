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

int n;
int w[N], d[N];

int preD[N], preW[N];
ll preWD[N];

ll dp[4][N];

void Init()
{
    FOR(i, 1, n + 1)
    {
        preD[i] = preD[i - 1] + d[i];
        preW[i] = preW[i - 1] + w[i];
        preWD[i] = preWD[i - 1] + 1LL * w[i] * preD[i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> w[i] >> d[i];

    Init();

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    FOR(i, 1, 3) FOR(r, 1, n + 1) REP(l, r)
        mini(dp[i][r], dp[i - 1][l] + 1LL * (preW[r] - preW[l]) * preD[r - 1] - (preWD[r] - preWD[l]));

    cout << dp[3][n + 1];

    return 0;
}