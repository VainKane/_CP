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

int n, x, y, z;
int a[4];
ll dp[2][N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> z;

    bool cur = 1;
    int i = 0;

    while (cin >> a[1] >> a[2] >> a[3])
    {
        i++;
        cur ^= 1;
        memset(dp[cur], 0, sizeof dp[cur]);
    
        FOR(cx, 0, min(x, i)) FOR(cy, 0, min(i - cx, y))
        {
            int cz = i - cx - cy;
            ll &val = dp[cur][cx][cy];
            if (cx) maxi(val, dp[cur ^ 1][cx - 1][cy] + a[1]);
            if (cy) maxi(val, dp[cur ^ 1][cx][cy - 1] + a[2]);
            if (cz) maxi(val, dp[cur ^ 1][cx][cy] + a[3]);
        }
    }

    cout << dp[cur][x][y];

    return 0;
}