#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1009;
int const M = 1e6 + 5;

int n;
long long a[N];
bool prime[M];

vector<int> primes;

int cnt[M];
map<long long, int> cntGCD;

long long GCD(long long a, long long b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, sqrt(1e6)) if (prime[i]) for (int j = i * i; j <= 1e6; j += i) prime[j] = false;
    FOR(i, 2, 1e6) if (prime[i]) primes.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Sieve();
    int res = 0;

    FOR(i, 1, n) for (auto &p : primes)
    {
        if (p > a[i]) break;
        maxi(res, cnt[p] += a[i] % p == 0);
    }

    FOR(i, 1, n) for (auto &p : primes)
    {
        if (p > a[i]) break;
        while (a[i] % p == 0) a[i] /= p;
    }

    FOR(i, 1, n) FOR(j, 1, n) cntGCD[GCD(a[i], a[j])]++;

    long long x = 1e18 + 1;
    int ma = 0;

    for (auto &p : cntGCD) if (p.F > 1 && maxi(ma, p.S)) x = p.F;

    int haha = 0;
    FOR(i, 1, n) haha += a[i] % x == 0;
    cout << max(haha, res);

    return 0;
}