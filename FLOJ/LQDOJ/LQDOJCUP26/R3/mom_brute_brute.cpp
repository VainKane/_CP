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
#define name "mom"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 36;

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

    sort(a, a + n);

    int res = 0;
    REP(mask, MK(n)) if (__builtin_parity(mask))
    {
        int sum = 0, cnt = __builtin_popcount(mask);
        vector<int> v;

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            v.push_back(a[i]);
            sum += a[i];
        }

        res += sum < v[cnt / 2] * cnt;
    }

    cout << res;

    return 0;
}