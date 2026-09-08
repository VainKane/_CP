#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "28D"

int const N = 1e5 + 5;

int n;
int a[N];

int dp[N];
int trace[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        dp[i] = 1;
    }

    int res = 0;
    int idx;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] <= a[j]) continue;

            if (dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                trace[i] = j;       
            }
        }

        if (res < dp[i])
        {
            res = dp[i];
            idx = i;
        }
    }

    vector<int> mark;

    while (idx)
    {
        mark.push_back(a[idx]);
        idx = trace[idx];
    }

    reverse(all(mark));

    cout << mark.size() << '\n';
    for (auto val : mark) cout << val << ' ';

    return 0;
}