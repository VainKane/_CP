#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "triple"

int const N = 5e6 + 5;

int n;
int p[N];
int cnt[N];

void Sieve()
{
    FOR(i, 1, n) p[i] = i;

    FOR(i, 2, sqrt(n)) if (p[i] == i) 
        for (int j = i * i; j <= n; j += i * i)
            while (p[j] % (i * i) == 0) p[j] /= i * i;

    FOR(i, 1, n) cnt[p[i]]++;
}

long long C3(int n)
{
    if (n < 3) return 0;
    return 1ll * n * (n - 1) * (n - 2) / 6;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    Sieve();

    long long res = 0;
    FOR(i, 1, n) res += C3(cnt[i]);
    cout << res;

    return 0;
}