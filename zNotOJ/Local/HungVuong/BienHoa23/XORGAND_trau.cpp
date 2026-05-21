#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "XORGAND"

int const N = 2e5 + 5;

int n, q;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> q;
    
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        int res = 0;
        FOR(i, l, r) res += ((a[i] ^ x) > (a[i] & x));
        cout << res << '\n';
    }

    return 0;
}