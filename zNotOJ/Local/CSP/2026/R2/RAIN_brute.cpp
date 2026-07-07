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
#define name "RAIN"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e5 + 5;

int n, q, t;
int a[N];

namespace Sub1
{
    bool CheckSub() { return n * q <= 1e8; }

    int pre[N], suf[N];
    ll res = 0, haha = 0;

    void Process()
    {
        while (q--)
        {
            int l, r, h;
            cin >> l >> r >> h;

            l = l ^ (t * res);
            r = r ^ (t * res);
            h = h ^ (t * res);

            pre[l - 1] = suf[r + 1] = 0;
            FOR(i, l, r) pre[i] = max(pre[i - 1], a[i]);
            FORD(i, r, l) suf[i] = max(suf[i + 1], a[i]);

            res = 0;
            FOR(i, l + 1, r - 1) res += max(0, min({h, pre[i - 1], suf[i + 1]}) - a[i]);
            haha ^= res;
        }

        cout << haha;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> q >> t;
    FOR(i, 1, n) cin >> a[i];

    if (Sub1::CheckSub()) return Sub1::Process(), 0;

    return 0;
}