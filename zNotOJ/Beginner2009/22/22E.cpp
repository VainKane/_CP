#include <bits/stdc++.h>

using namespace std;

int const N = 20;

int n;

int a[N + 5];
int b[N + 5];
int posA[N + 5];
int posB[N + 5];

long long dp[(1 << N) + 5];
int require[N + 5];

int bit(int const i, long long const mask)
{
    return (mask >> i) & 1;
}

long long TurnOn(int const i, long long const mask)
{
    return mask | (1ll << i);
}

long long TurnOff(int const i, long long const mask)
{
    return mask & (~(1ll << i));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= 1;
        posA[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] -= 1;
        posB[b[i]] = i;
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (posA[i] >= posA[j]) continue;
            if (posB[i] >= posB[j]) continue;

            require[j] = TurnOn(i, require[j]);
        }
    }

    dp[0] = 1;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (bit(i, mask)) continue;
            if ((mask & require[i]) != require[i]) continue;
            dp[TurnOn(i, mask)] += dp[mask];
        }
    }

    // for (int mask = 0; mask < (1 << n); mask++) cout << dp[mask] << ' ';
    cout << dp[(1 << n) - 1];

    return 0;
}