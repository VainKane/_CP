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

int const N = 4e5 + 5;
int const oo = 1e9;

int n;
long long s;

int a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    FOR(i, 1, n) cin >> a[i], a[n + i] = a[i];
    FOR(i, 1, 2 * n) pre[i] = pre[i - 1] + a[i];

    int res = oo;

    int l = 1;
    FOR(r, 1, 2 * n) while (pre[r] - pre[l - 1] >= s && l <= r)
    {
        mini(res, r - l + 1);
        l++;
    }

    if (res == oo) res = -1;
    cout << res;

    return 0;
}