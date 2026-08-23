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
ll oo = 1e18 + 9;

int n;
int a[N], c[N];

int id[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i] >> c[i];

    FOR(i, 1, n) id[i] = i;
    ll res = oo;

    do
    {
        id[n + 1] = id[1];

        ll cost = 0;
        FOR(i, 2, n + 1) cost += a[id[i]] == id[i - 1] ? 0 : c[id[i]];
        mini(res, cost);

    } while (next_permutation(id + 1, id + n + 1));

    cout << res;

    return 0;
}