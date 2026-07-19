#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const M = 1e7 + 15;

int n, t;
int a[N];
int p[N];
bool prime[M];

bool PrimeCheck(int x)
{
    if (x <= 1e7 + 10) return prime[x];
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

void Sieve()
{
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 1e7 + 10; i++)
    {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 1e7 + 10; j += i)
        {
            prime[j] = false;
        }
    }
}

bool Check(int x)
{
    int cnt = 0;
    for (int i = 0; i <= 9; i++)
    {
        cnt += PrimeCheck(x * 10 + i);
    }
    if (!cnt) return false;

    while (x)
    {
        if (!PrimeCheck(x)) return false;
        x /= 10;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> t;

    Sieve();
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + Check(a[i]);
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        cout << p[r] - p[l - 1] << '\n';    
    }

    return 0;
}