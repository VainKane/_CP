#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n, d;
int a[N];

int dp[N];
int res = 0;

void Update()
{
    FOR(i, 1, n)
    {
        dp[i] = 1;
        FOR(j, 1, i - 1) if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) FOR(j, i, n) FOR(x, -d, d)
    {
        FOR(k, i, j) a[k] += x;
        Update();
        FOR(k, i, j) a[k] -= x;
    }

    cout << res;

    return 0;
}