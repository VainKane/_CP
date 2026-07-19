#include <bits/stdc++.h>

using namespace std;

int Sum(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int a;
int b;

bool prime[63];

int count1 = 0;

int main()
{
    for (int i = 0; i <= 63; i++)
    {
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 63; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= 63; j += i)
            {
                prime[j] = false;
            }
        }
    }

    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        int num = Sum(i);

        if (prime[num])
        {
            count1 += 1;
        }
    }

    cout << count1;
}
