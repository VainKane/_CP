#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const M = 1e2 + 5;
int const N = 1e3 + 5;
int const MOD = 1e9 + 7;

int m, n;
int s[M], l[M];

int f[N][M];

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) cin >> s[i];
    FOR(i, 1, m) cin >> l[i];

    f[0][1] = 1;
    FOR(i, 1, n) FOR(j, 1, m) FOR(p, 1, m)
        f[i][j] = (f[i][j] + 1ll * f[i - 1][p] * (s[p] * (s[j] + l[j]) + l[p] * s[j])) % MOD;

    int res = 0;
    FOR(j, 1, m) Add(res, f[n][j]);
    cout << res;

    return 0;
}