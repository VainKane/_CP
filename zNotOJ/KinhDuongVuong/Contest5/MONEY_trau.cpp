#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 4e4 + 5;

int n, d;
int a[N];

long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];
   
    long long res = 0;
    while (d--)
    {
        int idx, val;
        cin >> idx >> val;
        a[idx] = val;

        dp[1] = a[1];
        FOR(i, 2, n) dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        res += *max_element(dp + 1, dp + n + 1);
    }

    cout << res;

    return 0;
}