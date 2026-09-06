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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e6 + 5;

bool prime[N];
vector<int> primes;

void Sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;

    FOR(i, 2, sqrt(2e6)) if (prime[i]) for (int j = i * i; j <= 2e6; j += i) prime[j] = false;
    FOR(i, 2, 2e6) if (prime[i]) primes.push_back(i);
}

bool Prime(ll x)
{
    if (x < 2) return false;
 
    int k = sqrt(x);
    for (auto &i : primes)
    {
        if (i > k) break;
        if (x % i == 0) return false;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Sieve();

    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        while (!Prime(++n));
        cout << n << '\n';
    }

    return 0;
}