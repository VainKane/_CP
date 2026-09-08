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

int n;
int a[N];

ll pre[N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];

        memset(dp, -0x3f, (n + 1) * sizeof(int));
        dp[0] = 0;

        FOR(i, 1, n) REP(j, i)
        {
            int val = 0;
            if (pre[i] - pre[j] > 0) val = i - j;
            else val = j - i;

            maxi(dp[i], dp[j] + val);
        }

        cout << dp[n] << '\n';
    }

    return 0;
}