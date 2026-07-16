#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

int const N = 155;

int n, l, r, k;
pair<int, int> a[N];

int dp[N][(int)1e4 + 5];
bool used[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r >> k;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        a[i] = {x, i};
    }

    // if (k >= n * (n - 1))
    // {
    //     sort(a + 1, a + n + 1, greater<int> ());
        
    //     int res = 0;
    //     FOR(i, 1, r - l + 1) res += a[i];
    //     cout << res;

    //     return 0;
    // }

    sort(a + l, a + r + 1);

    FOR(i, l, r) FOR(s, 0, k)
    {
        dp[i][s] = dp[i - 1][s] + a[i].F;
        
        int k = 0;
        FOR(j, 1, l - 1) if (!used[j])
        {
            int w = abs(j - a[i].S);
            int x = dp[i - 1][s - w] + a[j].F;

            if (s >= w && dp[i][s] < x)
            {
                k = j;
                dp[i][s] = x;
            }
        }
        
        FOR(j, r + 1, n) if (!used[j])
        {
            int w = abs(j - a[i].S);
            int x = dp[i - 1][s - w] + a[j].F;

            if (s >= w && dp[i][s] < x)
            {
                k = j;
                dp[i][s] = x;
            }
        }

        used[k] = true;

        // cout << a[i].F << ' ' << s << ' ' << dp[i][s] << '\n';
    }

    cout << dp[r][k];

    return 0;
}