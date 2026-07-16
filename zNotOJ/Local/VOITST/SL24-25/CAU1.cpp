#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU1"

long long GetSum(int l, int r)
{
    if (l > r) return 0;
    return (l + r) * (r - l + 1) / 2;
}

long long GetDivSum(int s, int l, int r)
{
    if (l > r) return 0;
    long long res = 0;

    FOR(i, l, r)
    {
        int val = s / i;
        int maxIdx = min(s / val, r);
        res += 1ll * (maxIdx - i + 1) * val;
        i = maxIdx;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int x, y;
    cin >> x >> y;

    int l = 2;
    int r = min(x - 1, y);
    int z = 0;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (mid - 1 <= x / (mid + 1))
        {
            z = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    long long res = GetSum(1, z - 1);
    res += GetDivSum(x, z + 2, min(x, y + 1));

    cout << res * (z != 0);

    return 0;
}
