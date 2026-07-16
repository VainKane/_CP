#include <bits/stdc++.h>

std::string Check(std::string str);

std::string str;

int main()
{
    getline(std::cin, str);

    std::cout << Check(str);
}

std::string Check(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '(' && str[i] != ')')
        {
            return "KHONG HOP LE";
        }
        else
        {
            if (str[i] == '(')
            {
                if (str[i + 1] == ')')
                {
                    str.erase(i, 2);
                    
                    if (i != 0)
                    {
                        i -= 2;
                    }
                    else
                    {
                        i -= 1;
                    }
                }
            }
        }
    }

    if (str.length() == 0)
    {
        return "DUNG";
    }
    else
    {
        return "KHONG DUNG";
    }
}