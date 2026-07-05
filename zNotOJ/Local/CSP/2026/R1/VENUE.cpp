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
#define name "VENUE"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e6 + 5;
int const oo = 2e9 + 9;

int n, m;
int a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    ii res = {oo, 0};
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if (a[j] < i) b[j] = min(i - a[j], m - i + a[j]);
            else b[j] = min(a[j] - i, m - a[j] + i);
        }

        mini(res, {*max_element(b + 1, b + n + n), i});
    }

    cout << res.F << ' ' << res.S;

    return 0;
}