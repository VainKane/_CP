#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 5009;

int n;
int a[N], b[N];
pair<int, int> tmp[N];

long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) 
        {
            cin >> b[i];
            tmp[i] = {b[i], a[i]};
        }

        sort(tmp + 1, tmp + n + 1, greater<pair<int, int>> ());
        FOR(i, 1, n)
        {
            a[i] = tmp[i].second;
            b[i] = tmp[i].first;
        }

        FOR(i, 1, n) FOR(j, 1, i)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i] + 1ll * (j - 1) * b[i]);

        FOR(i, 1, n) cout << dp[n][i] << ' ';
        cout << '\n';
    }

    return 0;
}