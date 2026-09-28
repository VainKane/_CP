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
#define name "TEAMS"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 22;
int const MOD = 1e9 + 7;
int const oo = 1e9 + 9;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    REP(i, n) cin >> a[i];

    int res = 0;
    FOR(mask, 1, MK(n) - 2)
    {
        int mn1 = oo, mn2 = oo;
        REP(i, n)
        {
            if (BIT(i, mask)) mini(mn1, a[i]);
            else mini(mn2, a[i]);
        }

        res = (res + 1LL * mn1 * mn2) % MOD;
    }

    cout << res;

    return 0;
}