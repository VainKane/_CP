#include <bits/stdc++.h>

using namespace std;

#define name "easytask"

int const N = 1e6 + 5;

int n;
int a[N];

long long p[N];
long long minP = 1e18;
long long res = -1e18;

bool prime[N];

int l = 1;
int r = 1e6;

void Sieve()
{
    memset(prime, 1, sizeof prime);
    for (int i = 2; i * i <= r; i++)
    {
        for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
        {
            prime[j - l] = false;
        }
    }
    if (1 >= l) prime[1 - l] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Sieve();

    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i];
        if (prime[i - l]) res = max(res, p[i] - minP);
        if (prime[i + 1 - l]) minP = min(minP, p[i]);
    }

    cout << res;

    return 0;
}
