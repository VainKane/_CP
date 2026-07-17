#include <bits/stdc++.h>

using namespace std;

int n;
int a[25009];

long long dp[25009];
int b[25009];

deque<int> res;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second) return true;
    else if (a.second == b.second) return a.first < b.first;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[1] = 1ll * a[1];
    dp[2] = 1ll * a[1] + a[2];
    dp[3] = 1ll * max(a[1], a[2]) + a[3];

    for (int i = 4; i <= n; i++)
    {
        long long s1 = dp[i - 1];
        long long s2 = dp[i - 2] + a[i];
        long long s3 = dp[i - 3] + a[i - 1] + a[i];

        if (dp[i] <= s1)
        {
            b[i] = i - 1; 
            dp[i] = s1;
        }
        if (dp[i] <= s2)
        {
            b[i] = i - 2;
            dp[i] = s2;
        }
        if (dp[i] <= s3)
        {
            b[i] = i - 3;
            dp[i] = s3;
        }
    }

    int i = n;
    while (i)
    {
        if (b[i] != i - 1 && b[i] != 0)
        {
            if (b[i] == i - 3) res.push_back(i - 1);
            res.push_back(i);
        }

        if (i == 3)
        {
            res.push_back(3);
            if (a[1] >= a[2]) res.push_back(1);
            else res.push_back(2);
        }
        else if (i <= 2)
        {
            res.push_back(1);
            if (i == 2) res.push_back(2);
        }
        
        i = b[i];
    }

    sort(res.begin(), res.end());

    // for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    // cout << '\n';
    // for (auto val : res) cout << val << ' ';
    // cout << '\n';

    cout << dp[n] << '\n';

    int cnt = 0;
    for (auto val : res)
    {
        if (cnt == 10)
        {
            cout << '\n';
            cnt = 10;
        }
        cout << val << ' ';
        cnt++;
    }

    return 0;
}