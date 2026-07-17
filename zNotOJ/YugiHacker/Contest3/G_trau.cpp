#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define name "interval"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, m;
int l[N], r[N], a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m) 
    {
        cin >> l[i] >> r[i] >> a[i];
        l[i]--; r[i]--;
    }

    long long res = 0;

    REP(mask, MK(n))
    {
        long long sum = 0;

        FOR(i, 1, m)
        {
            FOR(j, l[i], r[i]) if (BIT(j, mask))
            {
                sum += a[i];
                break;
            }
        }

        maxi(res, sum);
    }

    cout << res;

    return 0;
}