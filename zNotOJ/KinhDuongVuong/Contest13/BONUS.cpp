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

int const N = 309;
long long const oo = 1e18;

int m, n, k;

int a[N][N];

long long d1[N][N];
long long d2[N][N];

long long r1[N][N];
long long r2[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        memset(d1, 0, sizeof d1);
        memset(d2, 0, sizeof d2);
        memset(r1, 0, sizeof r1);
        memset(r2, 0, sizeof r2);

        FOR(x, x1, x2) FOR(y, y1, y2) d1[x][y] = max(d1[x - 1][y], d1[x][y - 1]) + a[x][y];
        FORD(x, x2, x1) FORD(y, y2, y1) d2[x][y] = max(d2[x + 1][y], d2[x][y + 1]) + a[x][y];

        FOR(y, y1, y2) 
        {
            FOR(x, x1, x2) r1[x][y] = max(r1[x - 1][y], d1[x][y] + d2[x][y] - a[x][y]);
            FORD(x, x2, x1) r2[x][y] = max(r2[x + 1][y], d1[x][y] + d2[x][y] - a[x][y]);
        }

        long long res = oo;
        FOR(x, x1, x2) FOR(y, y1, y2) 
        {
            long long val = max(r1[x - 1][y + 1], r2[x + 1][y - 1]);
            if (val) mini(res, val);
        }

        cout << res << '\n';
    }

    return 0;
}