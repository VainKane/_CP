#include <bits/stdc++.h>

using namespace std;

#define name "23on2b3"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    int q; cin >> q;
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        
        int res = 0;
        for (int i = l; i <= r; i++) res += ((i | a) == i);

        cout << res << '\n';
    }

    return 0;
}