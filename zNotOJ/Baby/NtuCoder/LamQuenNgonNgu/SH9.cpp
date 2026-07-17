#include <bits/stdc++.h>

using namespace std;

bool Check(int n)
{
    long long sum = 1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;

            if (i != sqrt(n))
            {
                sum += n / i;
            }
        }
    }

    if (sum > n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int l;
int r;

int cnt = 0;

int main()
{
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        if (Check(i))
        {
            cnt += 1;
        }
    }

    cout << cnt;
}