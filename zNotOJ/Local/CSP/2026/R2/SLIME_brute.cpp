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
#define name "SLIME"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e5 + 5;

int n, k, x;
int cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k >> x;
    FOR(i, 1, n)
    {
        int a, b, c, t;
        cin >> a >> b >> c >> t;

        int sz = 0, day = t;
        bool ok = true;

        while (day <= 5e5)
        {
            day++;
            if (ok) sz += a;
            else
            {
                sz -= b;
                if (sz < x) break;
            }

            if (sz >= c) ok = false;
            cnt[day] += sz >= x;
        }
    }

    int res = 0;
    FOR(i, 1, 5e5) res += cnt[i] >= k;
    cout << res;

    return 0;
}