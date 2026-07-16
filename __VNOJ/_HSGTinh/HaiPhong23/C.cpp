#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 5;

int n, m;
int a[N];
int p[N];

bool prime[(int)1e7 + 5];

int res = 0;

void Sieve()
{
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 1e7; i++)
    {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 1e7; j += i)
        {
            prime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];

    Sieve();

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        int s = p[v] - p[u - 1];
        if (s < 0) cout << "0\n";
        else cout << prime[s] << '\n';
    }

    return 0;
}