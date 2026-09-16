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

int const N = 36;

int n, k;
vector<int> a, x, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    a = x = res = vector<int>(n, n + 1);
    REP(i, n) cin >> a[i];

    REP(mask, MK(n)) if (__builtin_popcount(mask) == k)
    {
        vector<int> val;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            val.push_back(a[i]);
        }

        sort(all(val));
        int j = 0;
        REP(i, n) x[i] = BIT(i, mask) ? val[j++] : a[i];

        mini(res, x);
    }

    for (auto &val : res) cout << val << ' ';

    return 0;
}