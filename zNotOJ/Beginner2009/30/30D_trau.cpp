#include <bits/stdc++.h>

using namespace std;

struct Employee
{
    int l, r;
};

int const N = 1e5 + 5;

int n;
Employee a[N];
long long dp[N];
long long res = 0;

bool cmp(Employee a, Employee b)
{
    return a.r < b.r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("30D.inp", "r", stdin);
    // freopen("30D.ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = a[i].r - a[i].l;
        for (int j = 1; j < i; j++)
        {
            if (a[i].l >= a[j].r)
            {
                dp[i] = max(dp[i], 1ll * dp[j] + a[i].r - a[i].l);
            }
            else
            {
                dp[i] = max(dp[i], dp[j] - 2ll * a[j].r + a[i].r + a[i].l);
            }
        }

        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}