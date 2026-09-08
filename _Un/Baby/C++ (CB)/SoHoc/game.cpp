#include <bits/stdc++.h>

int times;

int n;

long long x;
long long y;

long long result;

int main()
{
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> x >> y >> n;

        if (n % 2 == 1)
        {
            x *= 2;
        }

        std::cout << std::max(x, y) / std::min(x, y) << '\n';
    }

}
