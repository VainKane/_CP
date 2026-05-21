#include <bits/stdc++.h>

using namespace std;

#define name "volleyball"

int t;
int k, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> k >> x >> y;
        cout << min(max(k, y + 2) - x, max(k, x + 2) - y) << ' ';
    }

    return 0;
}