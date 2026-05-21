#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "coprime"

int const N = 1e5 + 5;

int n;
long long a[N];

int dp[N];

long long GCD(long long a, long long b)
{
    while (true)
    {
        if (!a || !b || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) dp[i] = 1;
   
    FOR(i, 2, n) FOR(j, 1, i - 1) if (GCD(a[i], a[j]) == 1 && a[j] < a[i]) 
        dp[i] = max(dp[i], dp[j] + 1);

    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}