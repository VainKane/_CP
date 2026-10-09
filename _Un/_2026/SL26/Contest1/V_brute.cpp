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

int const N = MK(20) + 5;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, MK(n)) cin >> a[i];

    int q; cin >> q;
    while (q--)
    {
        int type, l, r, k;
        cin >> type >> l >> r >> k;

        if (type == 1)
        {
            int val; cin >> val;
            FOR(i, l, r) a[i ^ k] = val;
        }
        else
        {
            ll res = 0;
            FOR(i, l, r) res += a[i ^ k];
            cout << res << '\n';
        }
    }

    return 0;
}