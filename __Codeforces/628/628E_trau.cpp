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

int const N = 3009;

int m, n;
char a[N][N];

bool Check(int x, int y, int len)
{
    FOR(l, 0, len)
    {
        if (a[x][y + l] != 'z') return false;
        if (a[x + len][y + l] != 'z') return false;
        if (a[x + l][y + len - l] != 'z') return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    long long res = 0;
    FOR(i, 1, m) FOR(j, 1, n) FOR(len, 0, max(m, n)) res += Check(i, j, len);
    cout << res;

    return 0;
}