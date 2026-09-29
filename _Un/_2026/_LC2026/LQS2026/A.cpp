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

int const N = 1e4 + 5;

int n, w;
ii a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> w;
    FOR(i, 1, n) cin >> a[i].F, a[i].S = i;

    sort(a + 1, a + n + 1);

    ll res = 0;
    FOR(i, 2, n - 1)
    {
        vector<int> v = {0};
        FOR(j, 1, i - 1) if (a[j].S < a[i].S && a[j].F != a[i].F) v.push_back(a[j].F);
        if (sz(v) == 1) continue;

        int k = 0;
        FORD(j, n, i + 1) if (a[i].S < a[j].S && a[j].F != a[i].F)
        {
            while (k + 1 < sz(v) && 1LL * a[i].F + a[j].F + v[k + 1] <= w) k++;
            res += k;
        }
    }

    cout << res;

    return 0;
}