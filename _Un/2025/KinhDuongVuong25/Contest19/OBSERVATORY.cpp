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

int pre[N][N];

int GetSum(int top, int bot, int left, int right)
{
    return pre[bot][right] - pre[top - 1][right] - pre[bot][left - 1] + pre[top - 1][left - 1];
}

int Cal(int x)
{
    FOR(i, 1, m) FOR(j, 1, n) 
        pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + (a[i][j] >= x);
    
    int cnt = 0;
 
    FOR(i, 1, m - p + 1) FOR(j, 1, n - q + 1)
    {
        cnt += GetSum(i, i + p - 1, j, j + q - 1) >= (p * q + 2) / 2;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> p >> q;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    int l = 1;
    int r = 1e9;
    pair<int, int> res = {l, 1};

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int cnt = Cal(mid);
        
        if (cnt)
        {
            res = {mid, cnt};
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res.F << ' ' << res.S;

    return 0;
}