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

int n, k;
pair<int, char> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i].F;
    FOR(i, 1, n) cin >> a[i].S;

    sort(a + 1, a + n + 1);

    int res = 0;
    FOR(i, 1, n) if (a[i].S == 'R') FOR(j, i, n) if (a[j].S == 'L') res += a[j].F - a[i].F <= 2 * k && ((a[j].F & 1) == (a[i].F & 1));
    FOR(i, 1, n) FOR(j, i + 1, n) res += a[i].F == a[j].F;

    cout << res;

    return 0;
}