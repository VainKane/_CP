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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1509;

int m, n, k;

int a[N][N], b[N][N];
int pre[N][N];

int pre1[N][N], pre2[N][N];
int suf[N];

int res = 0;

int Get(int top, int bot, int left, int right)
{
    if (top < 1 || left < 1 || bot > m || right > n) return 0;
    if (top > bot || left > right) return 0;
    return pre[bot][right] - pre[top - 1][right] - pre[bot][left - 1] + pre[top - 1][left - 1];
}

int Get(int i, int j) { return Get(i, i + k - 1, j, j + k - 1); }

void Rotate()
{
    FOR(i, 1, m) FOR(j, 1, n) b[j][m - i + 1] = a[i][j];
    swap(m, n);
    FOR(i, 1, m) FOR(j, 1, n) a[i][j] = b[i][j];
}

void Solve()
{
    FOR(i, 1, m) FOR(j, 1, n) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];

    memset(pre1, 0, sizeof pre1);
    memset(pre2, 0, sizeof pre2);

    FOR(i, k, m) FOR(j, k, n) pre1[i][j] = max({pre1[i - 1][j], pre1[i][j - 1], Get(i - k + 1, j - k + 1)});
    FORD(i, m - k + 1, 1) FOR(j, k, n) pre2[i][j] = max({pre2[i + 1][j], pre2[i][j - 1], Get(i, j - k + 1)});

    suf[n - k + 2] = 0;
    FORD(j, n - k + 1, 1)
    {
        suf[j] = suf[j + 1];
        FOR(i, 1, m - k + 1) maxi(suf[j], Get(i, j));
    }

    FOR(i, 1, m - k + 1) FOR(j, k + 1, n - 2 * k + 1) maxi(res, Get(i, j) + pre1[m][j - 1] + suf[j + k]);
    FOR(i, k, m - k) FOR(j, k, n - k) maxi(res, pre1[i][j] + pre2[i + 1][j] + suf[j + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    REP(haha, 4) Solve(), Rotate();
    cout << res;

    return 0;
}