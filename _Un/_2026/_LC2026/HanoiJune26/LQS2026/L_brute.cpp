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

int const N = 2e5 + 5;
int const MOD = 1e9 + 7;

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

int n, q;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    int inv2 = PowMod(2, MOD - 2);
    while (q--)
    {
        int type, l, r, val;
        cin >> type >> l >> r;
        l++, r++;

        if (type == 1)
        {
            cin >> val;
            FOR(i, l, r) a[i] = val;
        }
        else
        {
            int res = 0;
            int p = inv2;

            int k = r - l + 1;

            int d1 = k + 2 * l - 1;
            int d2 = (k - 1LL * l * k + l - 1LL * l * l) % MOD;
            if (d2 < MOD) d2 += MOD;
            
            FOR(i, l, r)
            {
                p = p * (a[i] + 1LL) % MOD;
                int tmp = (1LL * d1 * i % MOD * a[i] + 1LL * d2 * a[i] - 1LL * i * i % MOD * a[i]) % MOD;
                res = (1LL * res + tmp + MOD) % MOD;
            }

            cout << 1LL * res * p % MOD << '\n';
        }
    }

    return 0;
}