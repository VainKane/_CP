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

int const N = 1e6 + 5;
int const MOD = 3e6 + 17;

void Add(int &x, int const &y, int delta)
{
    x += delta * y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return res;
}

long long d;
int k, p;

bool prime[N];
int f[N], inv[N];

int cntPrimes = 0;
vector<int> fact;

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    FOR(i, 2, sqrt(p)) if (prime[i]) for (int j = i * i; j <= p; j += i) prime[j] = false;
}

vector<int> GetFactor(long long x)
{
    vector<int> fact;
    FOR(i, 2, sqrt(x)) if (x % i == 0)
    {
        int pw = 0;
        while (x % i == 0) x /= i, pw++;
        fact.push_back(pw);
    }

    if (x > 1) fact.push_back(1);
    return fact;
}

void Init()
{
    f[0] = 1;
    FOR(i, 1, 1e6) f[i] = 1LL * f[i - 1] * i % MOD;

    inv[(int)1e6] = PowMod(f[(int)1e6], MOD - 2);
    FORD(i, 1e6 - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
}

int C(int n, int k)
{
    if (n < k) return 0;
    return 1LL * f[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int EC(int n, int k)
{
    return C(n + k - 1, k - 1);
}

int Cal(int cnt)
{
    int res = 1;
    for (auto &p : fact) res = 1LL * res * EC(p, k - cnt) % MOD;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> d >> k >> p;

    Sieve();
    Init();

    FOR(i, 2, p) cntPrimes += prime[i];
    fact = GetFactor(d);

    int res = 0;
    REP(cnt, k) res = (res + ((cnt & 1) ? -1LL : 1LL) * C(k, cnt) * Cal(cnt)) % MOD;
    cout << 1LL * (res + MOD) * C(cntPrimes, k) % MOD;

    return 0;
}