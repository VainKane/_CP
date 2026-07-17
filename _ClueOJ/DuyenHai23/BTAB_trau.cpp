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

int const N = 5e6 + 5;

int m, n;
int a[N], b[N];
int pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    FOR(i, 1, n) cin >> b[i];

    int res = 0;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        int k = 0;
        while (a[i + k] == b[j + k] && a[i + k] && i + k <= m && j + k <= n)
        {
            res += pre[i + k] - pre[i - 1] == 0;
            k++;
        }
    }

    cout << res;

    return 0;
}