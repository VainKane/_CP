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
#define name "GIFT"

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, q;
pair<int, int> a[N];

namespace Sub1
{
    bool CheckSub()
    {
        FOR(i, 1, n) if (a[i].S != 1) return false;
        return true;
    }

    long long pre[N];

    void Process()
    {
        sort(a + 1, a + n + 1);
        FOR(i, 1, n) pre[i] = pre[i - 1] + a[i].F;

        while (q--)
        {
            int type, m, k, t;
            cin >> type >> m >> k;

            int l = 0;
            int r = n;
            int idx = l;

            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (pre[mid] <= m)
                {
                    idx = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }

            int cnt = idx / k;

            if (type == 1)
            {
                cin >> t;
                cout << (cnt >= t) << '\n';
            }
            else cout << cnt << '\n';
        }
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        return n <= 5000 && q <= 5000;
    }

    pair<int, int> b[5009];
    long long pre[5009];
    int d[5009];

    void Process()
    {
        sort(a + 1, a + n + 1);

        FOR(i, 1, n)
        {
            pre[i] = pre[i - 1] + a[i].F;
            b[i] = a[i];
        }

        while (q--)
        {
            int type, m, k, t;
            cin >> type >> m >> k;

            FOR(i, 1, n)
            {
                a[i] = b[i];
                d[i] = 0;
            }

            int cnt = 0, s = m;
            int p = 0;

            FOR(i, 1, n - k + 1)
            {
                p += d[i];
                a[i].S += p;

                int x = min(1LL * a[i].S, s / (pre[i + k - 1] - pre[i - 1]));
                d[i + k] += x;
                p -= x;

                s -= x * (pre[i + k - 1] - pre[i - 1]);
                cnt += x;
            }

            if (type == 1)
            {
                cin >> t;
                cout << (cnt >= t) << '\n';
            }
            else cout << cnt << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i].F;
    FOR(i, 1, n) cin >> a[i].S;

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}
