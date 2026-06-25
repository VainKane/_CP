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
int const M = 1e4 + 5;

int n, x, y;
pair<int, int> a[N];

ii dp[2][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x >> y;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    sort(a + 1, a + n + 1);

    bool cur = 1;

    FOR(i, 1, n)
    {
        cur ^= 1;
        FOR(j, 0, y)
        {
            dp[cur][j] = dp[cur ^ 1][j];

            if (j >= a[i].S)
            {
                auto p = dp[cur ^ 1][j - a[i].S]; p.F++;
                maxi(dp[cur][j], p);
            }
            
            if (-dp[cur ^ 1][j].S + a[i].F <= x)
            {
                auto p = dp[cur ^ 1][j]; p.F++, p.S -= a[i].F;
                maxi(dp[cur][j], p);
            }
        }
    }

    cout << dp[cur][y].F;

    return 0;
}