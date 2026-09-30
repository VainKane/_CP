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

int const N = 1009;
int const oo = 1e9 + 9;

int n;
int a[N][N];

int dp2[N][N], dp5[N][N];

int Count(int x, int k)
{
    if (!x) return 0;

    int res = 0;
    while (x % k == 0) x /= k, res++;
    return res;
}

void PrintOne()
{
    if (!a[1][1] || !a[n][n])
    {
        cout << 1;
        exit(0);
    }
}

bool Check()
{
    FOR(i, 1, n) FOR(j, 1, n) if (!a[i][j]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    PrintOne();

    memset(dp2, 0x3f, sizeof dp2);
    memset(dp5, 0x3f, sizeof dp5);

    dp2[1][1] = Count(a[1][1], 2);
    dp5[1][1] = Count(a[1][1], 5);

    FOR(i, 1, n) FOR(j, 1, n) if (i != 1 || j != 1)
    {
        dp2[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) + Count(a[i][j], 2);
        dp5[i][j] = min(dp5[i - 1][j], dp5[i][j - 1]) + Count(a[i][j], 5);
    }

    int res = min(dp2[n][n], dp5[n][n]);
    if (Check()) mini(res, 1);
    cout << res;

    return 0;
}