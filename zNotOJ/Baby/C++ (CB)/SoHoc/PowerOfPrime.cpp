#include <bits/stdc++.h>

int Cal(int n, int p);
int Count(int n, int p);


int times;
int n;
int p;

int main()
{
    freopen("PowerOfPrime.inp", "r", stdin);
    freopen("PowerOfPrime.out", "w", stdout);

    std::cin >> times;
    
    for (int i = 0; i < times; i++)
    {
        std::cin >> n >> p;

        std::cout << Cal(n, p) << '\n';
    }

}

int Cal(int n, int p)
{
    int result = 0;

    for (int i = p; i <= n; i += p)
    {
        result += Count(i, p);
    }

    return result;
}


int Count(int n, int p)
{
    int count = 0;

    while (n % p == 0)
    {
        count += 1;
        n /= p;
    }

    return count;
}

