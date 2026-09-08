#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)1e4 + 10];
int p;

long long dp[(int)1e4 + 10];

int b[(int)1e4 + 10];
deque<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1ll * (a[i] - p) * (a[i] - p);
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (dp[i] >= dp[j] + 1ll * (a[i] - a[j] - p) * (a[i] - a[j] - p))
            {
                b[i] = j;
                dp[i] = dp[j] + 1ll * (a[i] - a[j] - p) * (a[i] - a[j] - p);
            }
        }
    }

    int i = n;
    while (i)
    {
        if (b[i] != 0) res.push_front(b[i]);
        i = b[i];
    }
    res.push_back(n);

    cout << dp[n] << '\n';
    cout << res.size() << '\n';
    for (auto val : res) cout << val << ' ';

    return 0;
}