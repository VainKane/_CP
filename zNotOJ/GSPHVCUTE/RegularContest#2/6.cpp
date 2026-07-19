#include <bits/stdc++.h>

using namespace std;

#define name "data"

int const N = 1e4 + 5;

int n, x;
int a[N];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    int l = 1;
    int r = n;

    while (l <= r)
    {
        if (a[l] + a[r] <= x) 
        {
            l++;
            r--;
        }
        else r--;

        res++;
    }

    cout << res;

    return 0;
}