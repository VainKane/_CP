#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

pair<int, int> p[(int)1e5 + 10];

long long Cal(int a, int b, long long n)
{
    if (n < a) return 0;
    return ((n - a) / b) + 1;
}

bool Check(long long d)
{
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += Cal(p[i].first, p[i].second, d);
        if (sum > k) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    long long l = 0;
    long long r = LLONG_MAX;
    long long mid;
    long long res = 0;

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (Check(mid))
        {
            res = mid + 1;
            l = mid + 1;
        }
        else    
        {
            r = mid - 1;
        }
    }

    cout << res;

    return 0;
}