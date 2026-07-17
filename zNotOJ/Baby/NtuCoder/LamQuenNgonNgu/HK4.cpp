#include <bits/stdc++.h>

using namespace std;

int Reverse(int n)
{
    int res = 0;

    while (n)
    {
        res += n % 10;
        n /= 10;
        res *= 10;
    }

    res /= 10;

    return res;
}

int n;
int res;

bool prime[(int)2e5 + 10];

int main()
{
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        prime[i] = true;
    }

    prime [0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    res = n;

    while (true)
    {
        if (res == Reverse(res) && prime[res])
        {
            cout << res;
            break;
        }

        res -= 1;
    }
}