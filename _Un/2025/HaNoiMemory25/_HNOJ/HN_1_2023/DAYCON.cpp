#include <bits/stdc++.h>

using namespace std;

#define name "DAYCON"

int const N = 1e6 + 5;

int n;
int a[N];
bool prime[N];

int res = 1e9;

void Sieve()
{
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 1e6; i++)
    {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 1e6; j += i)
        {
            prime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    Sieve();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int last = -1e9;
    for (int i = 1; i <= n; i++)
    {
        if (prime[a[i]]) 
        {
            res = min(res, i - last + 1);
            last = i;
        }
    }

    if (res == 1e9) res = -1;
    cout << res;

    return 0;
}