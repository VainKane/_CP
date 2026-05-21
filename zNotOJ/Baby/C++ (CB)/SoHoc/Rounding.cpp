#include <bits/stdc++.h>

void Round(long long &n);

long long n;

int main()
{
    freopen("Rounding.inp", "r", stdin);
    freopen("Rounding.out", "w", stdout);

    std::cin >> n;
    
    Round(n);

    std::cout << n;
}

void Round(long long &n)
{
    if (n % 10 <= 5)
    {
        n /= 10;
        n *= 10;
    }
    else
    {
        n /= 10;

        long long temp = n % 10;

        n /= 10;
        n *= 10;
        n += temp + 1;
        
        n *= 10; 
    }
}