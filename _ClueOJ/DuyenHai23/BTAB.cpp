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

int const N = 5e6 + 5;
int const M = 2240;
int const OS = 2237;

int m, n;
int a[N], b[N];

int cnt[M][2 * M];
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    if (m > n) swap(m, n), swap(a, b);
    dp.assign(m + 5, vector<int> (n + 5, 0));

    long long res = 0;
    int pre = OS;
    
    FOR(i, 1, m)
    {
        memcpy(cnt[i], cnt[i - 1], sizeof cnt[i]);
        cnt[i][pre += a[i]]++;

        FOR(j, 1, n)
        {
            dp[i][j] = a[i] == b[j] && a[i] ? dp[i - 1][j - 1] + 1 : 0;

            if (dp[i][j] == i && pre == OS) res++;
            res += cnt[i - 1][pre] - cnt[max(0, i - dp[i][j] - 1)][pre];
        }
    }

    cout << res;

    return 0;
}