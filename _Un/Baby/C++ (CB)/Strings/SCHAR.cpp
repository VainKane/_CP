#include <bits/stdc++.h>

int Search(std::string str);


std::string str;
int times;

int main()
{
    // freopen("BAI3.INP", "r", stdin);
    // freopen("BAI3.OUT", "w", stdout);

    std::cin >> times;
    std::cin.ignore();

    for (int i = 0; i < times; i++)
    {
        getline(std::cin, str);

        std::cout << Search(str) << '\n';
    }
}    

int Search(std::string str)
{
    int items[2][30];

    for (int i = 0; i < 30; i++)
    {
        items[0][i] = 0;
        items[1][i] = -1;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (items[0][str[i] - 'a'] == 0)
        {
            items[0][str[i] - 'a'] = 1;
            items[1][str[i] - 'a'] = i;
        }
        else
        {
            items[1][str[i] - 'a'] = -1;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (items[1][str[i] - 'a'] != -1)
        {
            return i + 1;
        }
    }

    return -1;
}