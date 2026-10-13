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

int const N = 1e6 + 5;
int const lim = 1e6;

int primeDiv[N];
vector<int> facts;

void Sieve()
{
    FOR(i, 2, sqrt(lim)) if (!primeDiv[i]) for (int j = i * i; j <= lim; j += i) primeDiv[j] = i;
    FOR(i, 2, lim) if (!primeDiv[i]) primeDiv[i] = i;
}

int Cal(int mask, int l, int r, int x)
{
    int p = 1;
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        p *= facts[i];
    }

    return r / p - l / p;
}

int Get(int l, int r, int x)
{
    int res = 0;
    REP(mask, MK(sz(facts))) res += (__builtin_parity(mask) ? -1 : 1) * Cal(mask, l, r, x);
    return res;
}

void Factor(int x)
{
    facts.clear();
    while (x > 1)
    {
        int p = primeDiv[x];
        while (x % p == 0) x /= p;
        facts.push_back(p);
    }

    if (x > 1) facts.push_back(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, x, p, k;
    cin >> q;

    Sieve();

    while (q--)
    {
        cin >> x >> p >> k;

        int l = x + 1, r = 1e7;
        int res = r;

        Factor(p);

        while (l <= r)
        {
            int mid = l + r >> 1;
            if (Get(x, mid, p) >= k) res = mid, r = mid - 1;
            else l = mid + 1;
        }

        cout << res << '\n';
    }

    return 0;
}