#include <bits/stdc++.h>

using namespace std;

#define bd(n) (int)(n + 5)
#define name "BAI4"

int const N = 1e6;

long long l, r;

int cntDiv[bd(N)];
bool isPrime[bd(N)];

int res = 0;

void Sieve()
{
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;

    for (int i = 1; i * i <= N; i++)
    {
        for (int j = i * i; j <= N; j += i)
        {
            cntDiv[j]++;
            if (i * i != j) cntDiv[j]++;

            if (isPrime[i]) isPrime[j] = false;
        }
    }
}

long long Count(long long x)
{
    int cnt = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0) 
        {
            cnt++;
            if (i * i != x) cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> l >> r;
    Sieve();

    int k = sqrt(l);
    if (k * k != l) k++;

    for (int i = k; 1ll * i * i <= r; i++)
    {
        int p = Count(1ll * i * i);

        if (isPrime[p])
        {
            res++;
            // cout << 1ll * i * i << ' ' << p << '\n';
        }
    }

    cout << res;

    return 0;
}