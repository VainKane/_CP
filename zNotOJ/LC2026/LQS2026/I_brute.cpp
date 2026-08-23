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

int const N = 2e5 + 5;
ll const oo = 1e18 + 9;

int n, m, f;
int a[N], b[N];

ll l[N], r[N];
int cnt[N];

ll dp[5009][5009];

void Reset()
{
    memset(l, 0, (n + 1) * sizeof(ll));
    memset(r, 0, (n + 1) * sizeof(ll));
    FOR(i, 0, n) memset(dp[i], -0x3f, (n + 1) * sizeof(ll));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> f;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m) cin >> b[i];

        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);

        Reset();

        int idx = 0;
        ll ma = -oo;

        FOR(i, 1, n)
        {
            cnt[i] = cnt[i - 1];
            while (idx < m && b[idx + 1] < a[i])
            {
                idx++;
                maxi(ma, -1LL * f * idx + 2 * b[idx]);
                cnt[i]++;
            }

            maxi(l[i], ma + 1LL * f * (cnt[i] + 1) - 2 * a[i]);
        }

        idx = m + 1, ma = -oo;
        FORD(i, n, 1)
        {
            while (idx > 1 && b[idx - 1] > a[i])
            {
                idx--;
                maxi(ma, 1LL * f * idx - 2 * b[idx]);
            }

            maxi(r[i], ma - 1LL * f * cnt[i] + 2 * a[i]);
        }

        dp[0][0] = 0;
        FOR(i, 1, n) FOR(x, 0, i)
        {
            if (x) maxi(dp[i][x], dp[i - 1][x - 1] + l[i] + a[i] - 1LL * f * cnt[i]);
            maxi(dp[i][x], dp[i - 1][x + 1] + r[i] - a[i] + 1LL * f * cnt[i]);
        }

        cout << dp[n][0] << '\n';
    }

    return 0;
}