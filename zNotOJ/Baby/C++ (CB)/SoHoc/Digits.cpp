#include <bits/stdc++.h>

int Count(int n);


int times;
int n;

int main()
{
    freopen("Digits.inp", "r", stdin);
    freopen("Digits.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> n;

        while ((n / 10) > 0)
        {  
            n = Count(n);
        }

        std::cout << n << '\n';
    }

}

    

int Count(int n)
{
    int result = 0;

    while (n > 0)
    {
        result += n % 10;
        n /= 10;
    }

    return result;
}

