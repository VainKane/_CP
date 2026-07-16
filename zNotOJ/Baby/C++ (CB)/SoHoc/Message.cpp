#include <bits/stdc++.h>

int Count(int n);

int times;
int n;

int main()
{
    freopen("Message.inp", "r", stdin);
    freopen("Message.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> n;
        std::cout << Count(n) << '\n';
    }
}

int Count(int n)
{
    if (n != 2)
    {
        return 2 * (n - 1);
    }
    else
    {
        return 2;    
    }
}