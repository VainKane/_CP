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

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;

int cnt[77];
int divMask[77];

vector<int> primes;
int dp[77][MK(19) + 5];

int pw[N];

bool IsPrime(int x)
{
    FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
    return x > 1;
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    FOR(i, 2, 70) if (IsPrime(i)) primes.push_back(i);
    FOR(x, 1, 70) 
    {
        int tmp = x;
        REP(i, sz(primes)) 
        {
            while (tmp % primes[i] == 0) 
            {
                divMask[x] ^= MK(i);
                tmp /= primes[i];
            }
        }
    }

    pw[0] = 1;
    FOR(i, 1, n) pw[i] = 2 * pw[i - 1] % MOD;

    dp[0][0] = 1;
    FOR(i, 1, 70) REP(mask, MK(19))
    {
        if (!cnt[i]) dp[i][mask] = dp[i - 1][mask];
        else dp[i][mask] = (1LL * (pw[cnt[i] - 1]) * (dp[i - 1][mask] + dp[i - 1][mask ^ divMask[i]])) % MOD;
    }

    cout << (dp[70][0] - 1 + MOD) % MOD;

    return 0;
}