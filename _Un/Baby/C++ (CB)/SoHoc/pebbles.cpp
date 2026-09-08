#include <bits/stdc++.h>

int n;
int k;

int value;

int bags;

int main()
{
    freopen("pebbles.inp", "r", stdin);
    freopen("pebbles.out", "w", stdout);

    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> value;

        if (value % k == 0)
        {
            bags += value / k;
        }
        else
        {
            bags += (value / k) + 1;
        }
    }

    if (bags % 2 == 0)
    {
        std::cout << bags / 2;
    }
    else
    {
        std::cout << (bags / 2) + 1;
    }
}