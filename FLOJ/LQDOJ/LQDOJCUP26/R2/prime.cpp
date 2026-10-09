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
#define name "prime"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e6 + 5;
int const lim = 1e6;
int MOD;

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

int n;
int a[N];

vector<int> facts[N];
int primeDiv[N];

int cnt[N];
int f[25 * N], inv[25 * N];

int haha = 0;

void Sieve()
{
    FOR(i, 2, sqrt(lim)) if (!primeDiv[i]) for (int j = i * i; j <= lim; j += i) primeDiv[j] = i;
    FOR(i, 2, lim) if (!primeDiv[i]) primeDiv[i] = i;
}

void Init()
{
    f[0] = 1;
    FOR(i, 1, haha) f[i] = 1LL * f[i - 1] * i % MOD;

    inv[haha] = PowMod(f[haha], MOD - 2);
    FORD(i, haha - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> MOD;
    FOR(i, 1, n) cin >> a[i];

    Sieve();
    FOR(i, 1, n)
    {
        int x = a[i];
        while (x > 1)
        {
            int p = primeDiv[x];
            cnt[p]++, x /= p;
        }
    }

    FOR(i, 2, lim) haha += cnt[i];
    Init();

    int res = f[haha];
    FOR(i, 2, lim) if (cnt[i]) res = 1LL * res * inv[cnt[i]] % MOD;
    cout << res;

    return 0;
}