#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "SUMX"

int const N = 1e5 + 5;

int n, x;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> x;

    sort(a + 1, a + n + 1);

    long long res = 0;
    FOR(i, 1, n)
    {
        auto it1 = lower_bound(a + i + 1, a + n + 1, x - a[i]);
        auto it2 = upper_bound(a + i + 1, a + n + 1, x - a[i]);

        res += it2 - it1;
    }

    cout << res;

    return 0;
}