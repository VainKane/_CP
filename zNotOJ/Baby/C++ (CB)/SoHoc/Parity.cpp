#include <bits/stdc++.h>

int Count(long long n);

int times;
long long n;

int main()
{
    freopen("Parity.inp", "r", stdin);
    freopen("Parity.out", "w", stdout);

    std::cin >> times;
    
    for (int i = 0; i < times; i++)
    {
        std::cin >> n;
        
        if (Count(n) % 2 == 0)
        {
            std::cout << "even\n";
        }
        else
        {
            std::cout << "odd\n";
        }
    }
}

int Count(long long n)
{
    int count = 0;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            count += 1;
        }

        n /= 2;
    }

    return count;
}