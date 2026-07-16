#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 101;
int const K = 1e5 + 5;
int const MOD = 1e9 + 7;

int n, k;

int a[N];
int pre[2][K], dp[K];

int cur = 0, nxt = 1;

int GetSum(int l, int r)
{
    if (l > r) return 0;
    if (l == 0) return pre[cur][r];
    return (pre[cur][r] - pre[cur][l - 1] + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 0, k) pre[nxt][i] = 1;
    FOR(i, 1, n) 
    {
        swap(cur, nxt);
        FOR(j, 0, k) 
        {
            dp[j] = GetSum(max(0, j - a[i]), j);
            pre[nxt][j] = (pre[nxt][j - 1] + dp[j]) % MOD;
        }
    }

    cout << dp[k];

    return 0;
}