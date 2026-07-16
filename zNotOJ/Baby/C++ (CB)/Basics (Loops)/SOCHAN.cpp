#include <bits/stdc++.h>

int n;
int count = 1;

int main()
{
    std::cin >> n;


    for (int i = 12; i <= n; i += 6)
    {
        count += 1;
    }

    std::cout << count << '\n';
    std::cout << 6;

    for (int i = 12; i <= n; i += 6)
    {
        std::cout << ' ' << i;
    }
}