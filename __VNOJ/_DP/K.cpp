#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e2 + 5;

int n, k;

int a[N];
bool dp[(int)1e5 + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    FOR(x, a[1], k) FOR(i, 1, n) 
    {
        if (x < a[i] || dp[x]) break;
        dp[x] |= !dp[x - a[i]];
    }

    cout << (dp[k] ? "First" : "Second");

    return 0;
}