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

int n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    int lb = 0, rb = 2 * n - 1;

    int res = 0;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (res == 0 && rb - lb + 1 != 2 * n)
        {
            cout << "0\n";
            continue;
        }

        l = (res + l) % n, r = (res + r) % n;

        if (r < l)
        {
            if (l > rb) mini(rb, r);
            else maxi(lb, l), mini(rb, n + r);
        }
        else maxi(lb, l), mini(rb, r);

        cout << (res = max(0, rb - lb + 1)) << '\n';
    }

    return 0;
}