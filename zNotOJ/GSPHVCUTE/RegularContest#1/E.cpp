#include <bits/stdc++.h>

using namespace std;

#define name "lcm"

int n;

long long GCD(long long a, long long b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long LCM(long long a, long long b)
{
    return a / GCD(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    long long res = 1;

    cin >> n;
    for (int x = max(1, n - 100); x <= n; x++)
    {
        for (int y = max(1, n - 100); y <= n; y++)
        {
            for (int z = max(1, n - 100); z <= n; z++)
            {
                res = max(res, LCM(LCM(x, y), z));
            }
        }
    }

    cout << res;

    return 0;
}