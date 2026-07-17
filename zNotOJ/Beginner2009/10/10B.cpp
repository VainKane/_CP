#include <bits/stdc++.h>

using namespace std;

int l1, c1;
int l2, c2;
int l3, c3;

int n;
int s;
int t;

int a[(int)1e4 + 10];
long long dp[(int)1e4 + 10];

long long Cal(int x)
{
    if (x < 0 || x > l3) return -1;

    if (x <= l1) return c1;
    else if (x <= l2) return c2;
    return c3;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> l1 >> l2 >> l3;
    cin >> c1 >> c2 >> c3;

    cin >> n;
    cin >> s >> t;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
    }

    s -= 1;
    t -= 1;

    int c = s;
    int d = t;

    s = min(c, d);
    t = max(c, d);

    for (int i = s + 1; i <= t; i++)
    {
        dp[i] = LLONG_MAX;
        for (int j = s; j < i; j++)
        {
            if (Cal(a[i] - a[j]) != - 1)
            {
                dp[i] = min(dp[i], dp[j] + Cal(a[i] - a[j]));
            }
        }
    }

    // for (int i = s; i <= t; i++) cout << dp[i] << ' ';
    cout << dp[t];

    return 0;
}