#include <bits/stdc++.h>

using namespace std;

int x[(int)1e5 + 10];
int k;
int n;

long long res = -1;

int s[(int)1e5 + 10];
int t[(int)1e5 + 10];

int d;

void Cal()
{
    int mi = INT_MAX;
    int ma = 0;
    long long sum = 0;

    for (int i = 1; i <= k; i++)
    {
        sum += (long long)s[x[i]];

        if (mi > t[x[i]])
        {
            mi = t[x[i]];
        }
        if (ma < t[x[i]])
        {
            ma = t[x[i]];
        }
    }

    if (ma - mi <= d)
    {
        if (sum > res)
        {
            res = sum;
        }
    }
}

void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;

        if (i == k)
        {
            Cal();
        }
        else
        {
            Try(i + 1);
        }
    }
}

int main()
{
    cin >> n >> k >> d;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> t[i];
    }

    Try(1);
    cout << res;

    return 0;
}
