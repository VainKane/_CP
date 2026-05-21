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

int const N = 67;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> n;

        FOR(i, 1, n) cin >> a[i];
        a[n + 1] = 0;

        long long res = 0;
        bool haha = true;

        while (haha)
        {
            haha = false;
            FOR(l, 1, n) if (a[l])
            {
                bool lmao = false;
                haha = true;

                int h = a[l];
                FOR(r, l + 1, n + 1)
                {
                    if (!a[r])
                    {
                        FOR(i, l, r - 1) a[i] -= h;
                        res += h;

                        // cout << l << ' ' << r - 1 << ' ' << h << '\n';

                        lmao = true;
                        break;
                    }
                    mini(h, a[r]);
                }

                if (lmao) break;
            }
        }

        cout << res << '\n';
    }

    return 0;
}