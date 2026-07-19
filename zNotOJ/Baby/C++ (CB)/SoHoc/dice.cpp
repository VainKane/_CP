#include <bits/stdc++.h>

int times;
int n;

int main()
{
    freopen("dice.inp", "r", stdin);
    freopen("dice.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> n;
        std::cout << 7 - n << '\n';
    }
}

