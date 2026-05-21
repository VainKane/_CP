#include <bits/stdc++.h>

std::string str;
int count[10] = {0};

int main()
{
    getline(std::cin, str);

    for (char chr : str)
    {
        if (chr >= '0' && chr <= '9')
        {
            count[chr - '0'] += 1;
        }
    }


    for (int i = 0; i < 10; i++)
    {
        std::cout << count[i] << ' ';
    }
}
