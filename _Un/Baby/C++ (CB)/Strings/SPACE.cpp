#include <bits/stdc++.h>

void Find(char chr, std::string str, int pos[2]);


std::string str;
int pos[2];

int main()
{
    getline(std::cin, str);

    Find(' ', str, pos);

    std::cout << pos[0] << ' ' << pos[1];
}

void Find(char chr, std::string str, int pos[2])
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == chr)
        {
            pos[0] = i;
            break;
        }
    }

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == chr)
        {
            pos[1] = i;
            break;
        }
    }
}

