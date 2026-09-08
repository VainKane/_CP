#include <bits/stdc++.h>

using namespace std;

int Sum(long long n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int n;
int nums[102];

int count1 = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long value;
        cin >> value;

        nums[i] = Sum(value);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((nums[i] + nums[j]) % 9 == 0 && j <= n)
            {
                count1 += 1;
            }
        }
    }

    cout << count1;
}