#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define ALL(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "LIGHT"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 670;

int n, q, x, y;
int a[N];

namespace Sub2
{
    bool CheckSub()
    {
        return x == 1 && y == 1;
    }

    int cnt1[N], cnt2[N];

    void Process()
    {
        FOR(i, 1, n)
        {
            cnt1[i] = cnt1[i - 1] + (a[i] == 1);
            cnt2[i] = cnt2[i - 1] + (a[i] == 2);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int c1 = cnt1[r] - cnt1[l - 1];
            int c2 = cnt2[r] - cnt2[l - 1];

            int res = 0;
            int k = min(c1, c2);

            res += k;
            c1 -= k;
            c2 -= k;

            if (c1 == 0)
            {
                if (c2 % 3 != 0)
                {
                    cout << "-1\n";
                    continue;
                }
                else res += (c2 / 3) * 2;
            }

            if (c2 == 0)
            {
                if (c1 % 3 != 0)
                {
                    cout << "-1\n";
                    continue;
                }
                else res += (c1 / 3) * 2;
            }

            cout << res << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q >> x >> y;
    FOR(i, 1, n) cin >> a[i];

    if (Sub2::CheckSub()) return Sub2::Process(), 0;

    return 0;
}
