#include <bits/stdc++.h>

using namespace std;

long long Kadane(long long a[], int n)
{
    long long sum = 0;
    long long res = LONG_LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        res = max(res, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return res;
}

long long MaxSum(long long a[], int n)
{
    long long sum = 0;
    int ind;
    long long mi = LONG_LONG_MAX;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (mi > sum)
        {
            mi = sum;
            ind = i;
        }
    }

    sum = 0;
    long long ma = LONG_LONG_MIN;

    for (int i = ind + 1; i < n; i++)
    {
        sum += a[i];
        ma = max(ma, sum);
    }

    return ma;
}

int a[509][509];
long long p[509][509];
long long b[509];

int n;
int m;

long long res = LONG_LONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
             cin >> a[i][j];
        }
    }

    for (int j = 0; j < n; j++)
    {
        p[0][j] = a[0][j];

        for (int i = 1; i < m; i++)
        {
            p[i][j] = p[i - 1][j] + a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i > 0) b[k] = p[j][k] - p[i - 1][k];
                else b[k] = p[j][k];
            }

            long long sum;
            
            sum = Kadane(b, n);
            // sum = MaxSum(b, n);

            res = max(res, sum);
        }
    }

    cout << res;

    return 0;
}