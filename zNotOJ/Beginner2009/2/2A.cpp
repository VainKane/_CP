#include <bits/stdc++.h>

using namespace std;

int Sum(long long n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

long long Solve(long long n)
{
    int ma = 0;
    long long res = LONG_LONG_MAX;

    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int s = Sum(i);

            if (s > ma)
            {
                ma = s;
                res = i;
            }
            else if (s == ma) 
            {
                res = min(res, i);
            }

            long long j = n / i;
            s = Sum(j);

            if (s > ma)
            {   
                ma = s;
                res = j;
            }
            else if (s == ma)
            {
                res = min(res, j);
            }
        }
    }

    return res;
}

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    cout << Solve(n);

    return 0;
}