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

int const N = sqrt(1e9) + 5;

int x;
vector<int> fact;

bool prime[N];
vector<int> primes;

long long c[67][67];

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    int bd = sqrt(1e9);
    FOR(i, 2, sqrt(bd)) if (prime[i]) for (int j = i * i; j <= bd; j += i) prime[j] = false;
    FOR(i, 2, bd) if (prime[i]) primes.push_back(i);
}

vector<int> GetFactor(int x)
{
    vector<int> fact;
    for (auto &p : primes)
    {
        if (p * p > x) break;
        if (x % p) continue;

        int pw = 0;
        while (x % p == 0) x /= p, pw++;
        fact.push_back(pw);
    }

    if (x > 1) fact.push_back(1);
    return fact;
}

void Init()
{
    c[0][0] = 1;
    FOR(n, 1, 60) FOR(k, 0, n)
    {
        c[n][k] = c[n - 1][k];
        if (k) c[n][k] += c[n - 1][k - 1];
    }
}

long long Cal(int k, int cnt)
{
    long long res = 1;
    for (auto &pw : fact) res *= c[pw + k - cnt - 1][k - cnt - 1];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Sieve();
    Init();

    int q; cin >> q;
    while (q--)
    {
        cin >> x;
        fact = GetFactor(x);
        
        int k = 0;
        for (auto &pw : fact) k += pw;

        long long res = 0;
        FOR(i, 1, k) REP(cnt, i) res += ((cnt & 1) ? -1 : 1) * c[i][cnt] * Cal(i, cnt);
        cout << res << '\n';
    }

    return 0;
}