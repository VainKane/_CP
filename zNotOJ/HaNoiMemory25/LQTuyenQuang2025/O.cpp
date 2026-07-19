#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n, k;

int a[N];
int cnt[N][35];

int FindMode(int l, int r)
{
    if (l > r) return 0;
    
    int res = 0;
    REP(i, 30) maxi(res, cnt[r][i] - cnt[l - 1][i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) REP(j, 30) cnt[i][j] = cnt[i - 1][j] + (a[i] == j);

    int res = 1;

    int j = 1;
    FOR(i, 1, n)
    {
        while (j - i + 1 - FindMode(i, j) <= k && j <= n) 
        {
            maxi(res, j - i + 1);
            j++;
        }
    }

    cout << res;

    return 0;
}