#include <bits/stdc++.h>

int result[29];

std::string str;

int main()
{
    getline(std::cin, str);

    for (char chr : str)
    {
        if (chr >= 'a' && chr <= 'z')
        {
            result[chr - 'a'] += 1;
        }
        else if (chr >= 'A' && chr <= 'Z')
        {
            result[chr - 'A'] += 1;
        }
    }


    for (int i = 0; i < 29; i++)
    {
        if (result[i] > 0)
        {
            std::cout << (char)('a' + i) << ' ' << result[i] << '\n';
        }
    }    
}