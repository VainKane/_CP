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
#define name "COW"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 8009;

int n;
int a[N], b[N];

int res[N];
int cnt = 0;

void Cal(int l, int r)
{
    int val = cnt;
    for (; l >= 1 && r <= n; l--, r++)
    {
        val += (a[l] == b[r]) - (a[l] == b[l]);
        val += (a[r] == b[l]) - (a[r] == b[r]);
        res[val]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, n) cnt += a[i] == b[i];
    FOR(i, 1, n) Cal(i, i), Cal(i, i + 1);

    FOR(i, 0, n) cout << res[i] << '\n';

    return 0;
}