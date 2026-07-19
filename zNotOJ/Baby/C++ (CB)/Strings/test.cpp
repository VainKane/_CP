#include <bits/stdc++.h>

int s1;
int s2;

int main()
{
    // std::cin >> s1 >> s2;

    // for (int i = 1; i <= s2 / 4; i++)
    // {
    //     if (2 * (s1 - i) + 4 * i == s2)
    //     {
    //         std::cout << s1 - i << ' ' << i;
    //     }
    // }

    int a[2][5] {
        {0, 3, 3, 4, 6},
        {3, 4, 7, 5, 5}
    };

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }

}