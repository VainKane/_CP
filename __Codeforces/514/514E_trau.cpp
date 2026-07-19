#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n, x;

int d[N];
int dp[(int)1e7 + 5];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    FOR(i, 1, n) cin >> d[i];

    int res = dp[0] = 1;

    FOR(i, 1, x) 
    {
        FOR(j, 1, n) if (i >= d[j]) Add(dp[i], dp[i - d[j]]);
        Add(res, dp[i]);
    }

    cout << res;

    return 0;
}