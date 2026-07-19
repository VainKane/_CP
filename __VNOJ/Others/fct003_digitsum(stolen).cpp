#include <bits/stdc++.h>
using namespace std;

long long a, b, dp[20][200][2];

/*
    dp[i][sum][k]: cách tạo ra số có i chữ số, có tổng các chữ số = sum
    k = 1: số đang xét nhỏ hơn số ban đầu (số ban đầu = a hoặc b)
    k = 0: số đang xét không nhỏ hơn số ban đầu
*/

long long DP(long long x) {

    vector<int> digit;
    while (x) {
        digit.push_back(x % 10);
        x /= 10;
    }
    reverse(digit.begin(), digit.end());

    int n = digit.size();
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int sum = 0; sum <= 135; sum++) { 
            for (int k = 0; k <= 1; k++) {
                int lim = k ? 9 : digit[i];
                for (int j = 0; j <= lim; j++) {
                    dp[i + 1][sum + j][k || (j != lim)] += dp[i][sum][k];
                }
            }
        }
    }

    long long res = 0;
    for (int sum = 1; sum <= 135; sum++) res += (dp[n][sum][0] + dp[n][sum][1]) * sum;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #define FILENAME "INOUT"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> a >> b;
    cout << DP(b) - DP(a - 1);

    return 0;
}
