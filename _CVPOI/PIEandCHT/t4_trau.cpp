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

int const N = 1e7 + 5;

long long d;
int k, p;

bool prime[N];

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    FOR(i, 2, sqrt(N)) if (prime[i]) for (int j = i * i; j < N; j += i) prime[j] = false;
}

bool Check(int x)
{
    int cnt = 0, cntPrime = 0;

    FOR(i, 2, sqrt(x)) if (x % i == 0)
    {
        cnt++;
        cntPrime += prime[i];

        if (prime[i] && i > p) return false;
        if (prime[x / i] && x / i > p) return false;

        if (i * i != x)
        {
            cnt++;
            cntPrime += prime[x / i];
        }
    }

    return cnt == d && cntPrime == k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> d >> k >> p;

    Sieve();

    int res = 0;
    FOR(x, 1, 1e6) res += Check(x), assert(!Check(x));
    cout << res;

    return 0;
}