#include <bits/stdc++.h>

using namespace std;

#define left asdf

int const N = 509;

int n, k, rq, p;
int a[N][N];

int top[N];
int left[N];

long long pre[N][N];

long long res = 0;  

void Init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
}

long long GetSum(int t, int b, int l, int r)
{
    if (t > b || l > r) return 0;
    return pre[b][r] - pre[b][l - 1] - pre[t - 1][r] + pre[t - 1][l - 1];
}

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

long long Cal()
{
    long long res = 0;

    for (int mask = 0; mask < (1 << p); mask++)
    {
        int t = 1;
        int b = n;
        int l = 1;
        int r = n;

        for (int i = 0; i < p; i++)
        {
            if (!bit(i, mask)) continue;

            t = max(t, top[i]);
            b = min(b, top[i] + rq - 1);
            l = max(l, left[i]);
            r = min(r, left[i] + rq - 1);
        }

        int k = __builtin_popcount(mask);
        if (k & 1) res -= GetSum(t, b, l, r);
        else res += GetSum(t, b, l, r);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> rq >> p;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }

    Init();

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> top[j] >> left[j];
        }
        res = max(res, pre[n][n] - Cal());
        // cout << Cal() << ' ';
    }

    cout << res;

    return 0;
}