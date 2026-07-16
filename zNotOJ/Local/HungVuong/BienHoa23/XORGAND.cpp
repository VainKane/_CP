#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "XORGAND"

int const N = 2e5 + 5;

int n;
int a[N];

int cnt[N][39];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n)
    {
        FOR(j, 1, 31) cnt[i][j] = cnt[i - 1][j];

        int k = __builtin_clz(a[i]);
        cnt[i][k]++;
    }

    int q; cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        int res = 0;
        FOR(k, 1, 31) if (k != __builtin_clz(x)) res += cnt[r][k] - cnt[l - 1][k];
        cout << res << '\n';
    }

    return 0;
}