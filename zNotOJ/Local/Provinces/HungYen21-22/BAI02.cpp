#include <bits/stdc++.h>

using namespace std;

#define name "BAI02"

int const N = 1e5 + 5;

int n;
int a[N];

bool prime[(int)2e6 + 5];

int res = 0;
int ma = 0;

void Sieve()
{
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 2e6; i++)
    {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 2e6; j += i)
        {
            prime[j] = false;
        }
    }
}

int Cal(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".out", "w", stdout);
    freopen(name".inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Sieve();
    
    for (int i = 1; i <= n; i++)
    {
        if (prime[a[i]] && ma < a[i])
        {
            ma = a[i];
            res = Cal(a[i]);
        }
    }

    cout << res;

    return 0;
}