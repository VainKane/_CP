#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 5;
int const M = 10;

int n;
int a[N];

int cnt[(1 << M) + 5];

int TurnOn(int i, int mask)
{
    return mask | (1 << i);
}

int GetMask(int x)
{
    int mask = 0;
    if (x == 0) mask = TurnOn(0, mask);

    while (x)
    {
        mask = TurnOn(x % 10, mask);
        x /= 10;
    }

    return mask;
}

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        cnt[GetMask(a[i])]++;
    }

    for (int mask1 = 0; mask1 < (1 << M); mask1++)
    {
        res += (1ll * cnt[mask1] * (cnt[mask1] - 1)) / 2;
        for (int mask2 = mask1 + 1; mask2 < (1 << M); mask2++)
        {
            if (!(mask1 & mask2)) continue;
            res += 1ll * cnt[mask1] * cnt[mask2];
        }
    }

    cout << res;

    return 0;
}