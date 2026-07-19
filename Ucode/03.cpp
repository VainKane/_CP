#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e4 + 5;

int n, m;
int a[N], b[N];

int CountSmaller(int x)
{
    int res = 0;

    int i = n;
    int j = 1;

    while (i >= 1 && j <= m)
    {
        if (a[i] + b[j] <= x)
        {
            res += i;
            j++;
        }
        else i--;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int l = -2e9;
    int r = 2e9;
    int res = 0;

    int k = (m * n + 1) / 2;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (CountSmaller(mid) >= k)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}