#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 5;

int t;
int n;
int a[N];

void Solve()
{
    long long res = 1e18;
   
    for (int l = 1, r = 1; l <= n;)
    {
        r = l;
        while (a[r + 1] == a[l] && r < n) r++;
        res = min(res, a[l] * (l - 1ll) + 1ll * (n - r) * a[l]);
        l = r + 1;
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        Solve();
    }

    return 0;
}