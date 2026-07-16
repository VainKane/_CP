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

int const N = 1e4 + 2277;

int n;
long long a[N];

vector<int> primes = {0};

bool Check(int x)
{
    FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
    return x > 1;
}

void Init()
{
    int x = 1;
    while (sz(primes) != 2e4 + 5) if (Check(++x)) primes.push_back(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    int cnt = 0;
    FOR(i, 1, 1e4) a[i] = 1;
    FOR(i, 1, 1e4)
    {
        a[i] *= primes[++cnt];
        a[i + 1] *= primes[cnt];
    }

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}