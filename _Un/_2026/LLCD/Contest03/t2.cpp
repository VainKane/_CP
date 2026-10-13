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
#define y1 dsfhjksdfksdf

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 36;
int const oo = 3e4 + 9;

int n;
int x1[N], x2[N], y1[N], y2[N];

int Cal(int mask)
{
    int t = -1, b = oo;
    int l = -1, r = oo;

    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        maxi(t, y1[i]), mini(b, y2[i]);
        maxi(l, x1[i]), mini(r, x2[i]);
    }

    if (t > b || l > r) return 0;
    return (b - t) * (r - l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    int res = 0;
    FOR(mask, 1, MK(n) - 1) res += (__builtin_parity(mask) ? 1 : -1) * Cal(mask);
    cout << res;

    return 0;
}