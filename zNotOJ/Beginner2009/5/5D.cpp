#include <bits/stdc++.h>

using namespace std;

long long TotalTime(long long a[], int n, int t, int k, long long &maxTime)
{
    long long res = 0;
    int j = 0;

    maxTime = 0;

    for (int i = 0; i < n; i++)
    {   
        while (1LL * t + k * j < a[i]) j++;
        res += (1LL * t + k * j - a[i]);

        maxTime = max(maxTime, 1LL * t + k * j - a[i]);
    }

    return res;
}

int n;
int k;

long long a[(int)1e5 + 10];

long long minTime = LONG_LONG_MAX;
long long minSum = LONG_LONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i <= k; i++)
    {
        long long maxTime = 0;
        minSum = min(minSum, TotalTime(a, n, i, k, maxTime));
        minTime = min(minTime, maxTime); 
    }

    cout << minSum << '\n' << minTime;

    return 0;
}