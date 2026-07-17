#include <bits/stdc++.h>

using namespace std;

#define name "CAU1"

int x, y;

int Solve()
{
    int cnt = 0;
    if (x > y) swap(x, y);

    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            cnt += (y % i == 0);
            cnt += (i * i != x && y % (x / i) == 0);
            // if (x != y) cnt += (i * i != y && x % (y / i) == 0);
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> x >> y;
    cout << Solve();

    return 0;
}