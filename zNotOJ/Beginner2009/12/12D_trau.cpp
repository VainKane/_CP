#include <bits/stdc++.h>
using namespace std;
long long minCost(int N, vector<long long> &A)
{
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for (int length = 2; length < N; ++length)
    {
        for (int i = 0; i + length < N; ++i)
        {
            int j = i + length;
            dp[i][j] = LLONG_MAX;
            for (int k = i + 1; k < j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + 1ll * A[i] * A[k] * A[j]);
        }
    }

    return dp[0][N - 1];
}

int main()
{
    freopen("12D.inp", "r", stdin);
    freopen("12D.ans", "w", stdout);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    cout << minCost(N, A);

    return 0;
}