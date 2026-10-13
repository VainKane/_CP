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

int const K = 36;

ll n;
int k;

ll a[K];

ll Cal(int mask)
{
    ll p = 1;
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        if (p > n / a[i]) return 0;
        p *= a[i];
    }

    return n / p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    REP(i, k) cin >> a[i];

    ll res = 0;
    FOR(mask, 1, MK(k) - 1) res += (__builtin_parity(mask) ? 1 : -1) * Cal(mask);
    cout << res;

    return 0;
}