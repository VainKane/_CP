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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;

int subtask;

int n, q;
int a[N];

namespace Sub1
{
    void Process()
    {
        while (q--)
        {
            int x, l, r;
            cin >> x >> l >> r;

            FOR(i, l, r) x = abs(x - a[i]);
            cout << x << '\n';
        }
    }
}

namespace Sub2
{
    int pre[N];

    void Process()
    {
        FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
        while (q--)
        {
            int x, l, r;
            cin >> x >> l >> r;

            cout << x - pre[r] + pre[l - 1] << '\n';
        }
    }
}

namespace Sub3
{
    void Process()
    {
        while (q--)
        {
            int x, l, r;
            cin >> x >> l >> r;

            int k = min(x / a[1], r - l + 1);
            x -= k * a[1];

            if ((r - l + 1 - k) & 1) x = a[1] - x;
            cout << x << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> subtask;
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    if (subtask == 1) return Sub1::Process(), 0;
    if (subtask == 2) return Sub2::Process(), 0;
    if (subtask == 3) return Sub3::Process(), 0;

    return 0;
}
