#include <bits/stdc++.h>

using namespace std;

#define name "BAI03"

int const N = 1e6 + 5;

int n, m;
int a[N];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    int l = 1;
    int r = n;

    while (l < r)
    {
        if (a[l] + a[r] <= m)
        {
            res += r - l;
            l++;
        }
        else r--;
    }

    cout << res;

    return 0;
}