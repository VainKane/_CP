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

int const N = 1e6 + 5;

int n;
long long m;

int a[N];
long long pre[N];

bool Check(int len)
{
    FOR(i, len, n) if (pre[i] - pre[i - len] < m) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];

    int l = 1;
    int r = n + 1;
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    if (res == n + 1) res = -1;
    cout << res;

    return 0;
}