#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e7 + 5;

bool prime[N];
long long pre[N];
int cnt[N];

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
    FOR(i, 1, 1e7) 
    {
        pre[i] = pre[i - 1];
        if (prime[i]) pre[i] += i;

        cnt[i] = cnt[i - 1] + prime[i];
    }

    int n; cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;

        long long s = pre[b] - pre[a - 1];

        if (s) cout << fixed << setprecision(2) << (double)s / (cnt[b] - cnt[a - 1]) << '\n';
        else cout << "0.00\n";
    }

    return 0;
}