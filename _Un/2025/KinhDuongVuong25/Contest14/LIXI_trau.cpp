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
#define name "LIXI"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, k;

int a[N];
long long pre[N];

long long GetSum(int l, int r)
{
    if (l > r) return 0;
    return pre[r] - pre[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            pair<int, int> b[k + 1];
            REP(i, k)
            {
                cin >> b[i].F;
                b[i].S = a[b[i].F];
            }

            if (k == 1) continue;

            b[k] = b[0];
            REP(i, k) a[b[i].F] = b[i + 1].S;

            FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
        }
        else
        {
            int l, r, m;
            cin >> l >> r >> m;

            long long res = 0;
            FOR(i, l, r - m + 1) res += GetSum(i, i + m - 1);
            cout << res << '\n';
        }
    }

    return 0;
}
