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

int const N = 5009;
int const oo = 1e9;

int n, k, p, m;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    a[0] = oo;

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k >> p >> m;
        FOR(i, 1, n) cin >> a[i];

        int res = 0;

        while (true)
        {
            while (p > k)
            {
                int idx = min_element(a + 1, a + k + 1) - a;
                if (a[idx] > m) break;

                m -= a[idx];
                p--;
                FOR(i, idx, n - 1) swap(a[i], a[i + 1]);
            }

            if (p > k) break;
            else
            {
                if (m < a[p]) break;
                m -= a[p];
                FOR(i, p, n - 1) swap(a[i], a[i + 1]);
                p = n;
                res++;
            }
        }

        cout << res << '\n';
    }

    return 0;
}