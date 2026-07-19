#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n;
bool prime[N];

void Sieve(int n)
{
    memset(prime, true, sizeof prime);
    FOR(i, 2, sqrt(n)) for (int j = i * i; j <= n; j += i) prime[j] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    Sieve(n + 1);

    if (n == 1) cout << "1\n1";
    else if (n == 2) cout << "1\n1 1";
    else
    {
        cout << "2\n";
        FOR(i, 1, n) cout << 1 + prime[i + 1] << ' ';
    }

    return 0;
}