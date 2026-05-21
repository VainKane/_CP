#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "SEQ"

int const N = 1009;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n)
    {
        long long res = 0;
        FOR(j, 1, n) res += 1ll * abs(i - j) * abs(a[i] - a[j]);

        cout << res << ' ';
    }

    return 0;
}
