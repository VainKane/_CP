#include <bits/stdc++.h>

using namespace std;

int n, k;

void Solve()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += (32 - __builtin_clz(i) - __builtin_popcount(i) == k);
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n >> k)
    {
        if (n == 0 && k == 0) return 0;
        Solve();
    }

    return 0;
}