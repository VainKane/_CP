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

int const N = sqrt(1e9) + 67;

int n, p, bd;
int pw[N];

bool prime[N];

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = false;
    FOR(i, 2, sqrt(bd)) if (prime[i]) for (int j = i * i; j <= bd; j += i * i) prime[j] = false;
}

void Init()
{
    FOR(i, 1, N)
    {
        pw[i] = 1;
        REP(haha, p + 1)
        {
            if (1LL * pw[i] * i > n)
            {
                bd = i - 1;
                return;
            }

            pw[i] = 1LL * pw[i] * i;
        }
    }
}

bool Parity(int x)
{
    bool par = 0;
    FOR(i, 2, sqrt(x)) if (x % i == 0) x /= i, par ^= 1;
    return par ^ (x > 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;

    Init();
    Sieve();

    int res = 0;
    FOR(i, 1, bd) if (prime[i]) res += (Parity(i) ? -1 : 1) * (n / pw[i]);
    cout << res - 1;

    return 0;
}