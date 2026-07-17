#include <bits/stdc++.h>

std::string Find(char chr, std::string str);

char x;
std::string str;
int count;

int main()
{
    std::cin >> x;
    std::cin.ignore();
    
    getline(std::cin, str);

    for (char chr : str)
    {
        if (chr == x)
        {
            count += 1;
        }
    }

    std::cout << count << '\n';

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == x)
        {
            std::cout << i << ' ';
        }
    }
}