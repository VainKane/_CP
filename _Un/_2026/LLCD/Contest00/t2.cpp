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

int const N = 5e5 + 5;
int const lim = 5e5;

int n;
int a[N];

int cnt[N], g[N];
ll f[N];
int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n)
    {
        cnt[a[i]] += (a[i] + 1) / 2, sum += (a[i] + 1) / 2;
        g[a[i]]++;
        f[a[i]] += a[i];
    }
    FORD(i, lim, 2) for (int j = 2 * i; j <= lim; j += i)
    {
        cnt[i] += cnt[j], g[i] += g[j];
        f[i] += f[j];
    }

    int res = 0;
    FOR(i, 2, n)
    {
        res += sum - 1LL * (i - 1) * g[i] * cnt[i] + f[i];
        cout << res << '\n';
    }

    // cout << f[2];
    // cout << cnt[2];
    // cout << cnt[2] - f[2];
    // cout << sum - (cnt[2] - f[2]);

    return 0;
}