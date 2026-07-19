#include <bits/stdc++.h>

using namespace std;

#define name "PRIME"

int const N = 1e6 + 5;

int n;
int a[N];

bool prime[N];
int cntDiv[N];

int res = 0;
int ma = 0;

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

    for (int i = 2; i <= 1e6; i++)
    {
        if (!prime[i]) continue;
        for (int j = i; j <= 1e6; j += i) cntDiv[j]++;
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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (ma < cntDiv[a[i]])
        {
            ma = cntDiv[a[i]];
            res = a[i];
        }
    }
    
    cout << res;

    return 0;
}