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

int m, n;
vector<vector<int>> a;
vector<vector<bool>> mark;

void Update(int &i, int &j, int &val)
{
    if (a[i][j] >= val) mark[i][j] = true;
    maxi(val, a[i][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    a.assign(m + 5, vector<int> (n + 5, 0));
    mark.assign(m + 5, vector<bool> (n + 5, false));

    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m)
    {
        int ma = 0;
        FOR(j, 1, n) Update(i, j, ma);

        ma = 0;
        FORD(j, n, 1) Update(i, j, ma);
    }

    FOR(j, 1, n)
    {
        int ma = 0;
        FOR(i, 1, m) Update(i, j, ma);

        ma = 0;
        FORD(i, m, 1) Update(i, j, ma);
    }

    int res = 0;
    FOR(i, 1, m) FOR(j, 1, n) res += mark[i][j];
    cout << res;

    return 0;
}