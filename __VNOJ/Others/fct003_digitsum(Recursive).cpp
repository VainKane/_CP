#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

long long a, b;

int n;
int x[20];
long long dp[20][2][140];

long long F(int idx, bool smaller, int sum)
{
    if (idx < 0) return sum;

    long long &res = dp[idx][smaller][sum];
    if (res != -1) return res;
    res = 0;

    int lim = smaller ? 9 : x[idx];
    FOR(d, 0, lim) res += F(idx - 1, smaller | (d < lim), sum + d);
    return res;
}

long long Get(long long k)
{
    memset(dp, -1, sizeof dp);

    n = 0;
    while (k)
    {
        x[n++] = k % 10;
        k /= 10;
    }

    return F(n - 1, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    cout << Get(b) - Get(a - 1);

    return 0;
}