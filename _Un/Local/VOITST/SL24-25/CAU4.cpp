#include <bits/stdc++.h>

using namespace std;

#define name "CAU4"

long long n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> a >> b;

    long long l = 1;
    long long r = a + b;
    long long res = 1;

    while (l <= r)
    {
        long long mid = (l + r) / 2ll;
        if (a / mid + b / mid >= n)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << min({res, a, b});

    return 0;
}
