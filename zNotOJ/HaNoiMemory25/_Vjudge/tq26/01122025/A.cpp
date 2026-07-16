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
#define name "MARIO"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const oo = 1e6;
int const os = 1e6 + 1;

int n, x, k;
long long pre[(int)2e6 + 97];

long long GetSum(int l, int r)
{
    if (l > r) return 0;
    return pre[r + os] - pre[l - 1 + os];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> x >> k;
    FOR(i, 1, n)
    {
        int x, w;
        cin >> x >> w;
        pre[x + os] += w;
    }

    FOR(i, -oo, oo) pre[i + os] += pre[i - 1 + os];

    long long res = 0;
    
    FOR(l, max(-oo, x - k), x)
    {
        int r = min(oo, k + 2 * l - x);
        maxi(res, GetSum(l, x) + GetSum(x + 1, r));
    }

    FOR(r, x, min(oo, x + k))
    {
        int l = max(2 * r - x - k, -oo);
        maxi(res, GetSum(l, x) + GetSum(x + 1, r));
    }

    cout << res;

    return 0;
}