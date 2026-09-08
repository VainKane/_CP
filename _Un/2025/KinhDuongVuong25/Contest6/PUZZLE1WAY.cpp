#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3009;
int const oo = N;

int n;
int a[N];

int cnt[N][N];
int dp[N][N];
int f[N];

void Init()
{
    memset(dp, 0x3f, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    memset(f, 0x3f, sizeof f);
    f[1] = 0;

    FOR(r, 1, n) FORD(l, r - 1, 1)
        cnt[l][r] = cnt[l + 1][r] + (l + a[l] >= r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
    
        Init();
    
        FOR(x, 0, a[1]) dp[x + 1][1] = cnt[2][x + 1];
        FOR(i, 3, n)
        {
            FOR(j, 1, i - 1) if (j + a[j] >= i)
            {
                FOR(p, 1, j - 1) if (p + a[p] < i) mini(dp[i][j], dp[j][p] + cnt[j + 1][i]);
                // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
            }
        }

        cout << *min_element(dp[n] + 1, dp[n] + n + 1) << '\n';
        // cout << dp[5][1];
        // cout << cnt[1][5];

        // FOR(i, 1, n) cout << f[i] << ' ';
    }

    return 0;
}