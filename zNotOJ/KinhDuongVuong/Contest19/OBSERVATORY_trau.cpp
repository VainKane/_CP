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

int const N = 1009;

int m, n, p, q;
int a[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> p >> q;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    int res = 0, cnt = 0;

    FOR(i, 1, m - p + 1) FOR(j, 1, n - q + 1)
    {
        vector<int> v = {0};
        FOR(x, i, i + p - 1) FOR(y, j, j + q - 1) v.push_back(a[x][y]);

        sort(all(v));
        if (maxi(res, v[(p * q + 1) / 2])) cnt = 1;
        else if (res == v[(p * q + 1) / 2]) cnt++;
    }

    cout << res << ' ' << cnt;

    return 0;
}