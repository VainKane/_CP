#include <bits/stdc++.h>

using namespace std;

#define name "29C"

int const N = 1e5 + 5;

int n;
int m;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    cin >> m;
    while (m--)
    {
        int t;
        cin >> t;

        int k = lower_bound(a + 1, a + n + 1, t) - a;
        for (int i = k; i <= n; i++) a[i]--;
        cout << n - k + 1 << '\n';
    }

    return 0;
}