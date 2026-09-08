#include <bits/stdc++.h>

using namespace std;

#define name "Trochoi"

typedef long long ll;

int const N = 1e6 + 5;

int n;

ll a[N];
ll sum[N];

ll l = 1e18;
ll r = 0;

void Sieve()
{
    for (ll i = 1; i * i <= r; i++)
    {
        for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
        {
            sum[j - l] += i;
            if (i * i != j) sum[j - l] += j / i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }

    Sieve();

    for (int i = 1; i <= n; i++) cout << sum[a[i] - l] << ' ';

    return 0;
}
