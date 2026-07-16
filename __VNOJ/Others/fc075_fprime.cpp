#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

bool prime[(int)1e7 + 5];

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, sqrt(1e7)) if (prime[i]) for (int j = i * i; j <= 1e7; j += i) prime[j] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Sieve();

    int k, n;
    cin >> k;

    while (k--)
    {
        cin >> n;
        if (n <= 1) cout << "NO\n";
        else cout << (prime[n] ? "YES\n" : "NO\n");
    }

    return 0;
}