#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "GONME"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1009;
int const M = 11;

int n, m;
int a[M][N];
int pos[M][N];

bool f[N][N];

int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(k, 1, m) FOR(i, 1, n) cin >> a[k][i], pos[k][a[k][i]] = i;

    FOR(i, 0, n) FOR(j, 0, n)
    {
        f[i][j] = true;
        FOR(k, 1, m) if (pos[k][i] < pos[k][j])
        {
            f[i][j] = false;
            break;
        }
    }

    FOR(i, 1, n) FOR(j, 0, i - 1) if (f[a[1][i]][a[1][j]])
        maxi(dp[i], dp[j] + 1);

    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}