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

int const N = 2009;

int m, n;

int col[N], row[N];
int sumCol[N], sumRow[N];

bitset<N> a[N];

long long C2(int x)
{
    return 1LL * x * (x - 1) / 2;
}

string ToString(__int128_t x)
{
    string res = "";
    while (x)
    {
        res.push_back(x % 10 + '0');
        x /= 10;
    }

    if (res.empty()) res.push_back('0');

    reverse(all(res));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        char ch; cin >> ch;
        a[i][j] = ch - '0';

        row[i] += a[i][j];
        col[j] += a[i][j];
    }

    FOR(j, 1, n) FOR(i, 1, m) if (a[i][j]) sumCol[j] += row[i] - 1;
    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j]) sumRow[i] += col[j] - 1;

    __int128 res = 0;
    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j])
        res += 2LL * (sumCol[j] - row[i] + 1) * (sumRow[i] - col[j] + 1);

    FOR(i, 1, m) FOR(j, i + 1, m) res -= C2((a[i] & a[j]).count()) * 8;
    cout << ToString(res);

    return 0;
}