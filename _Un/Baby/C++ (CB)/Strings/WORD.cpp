#include <bits/stdc++.h>

std::string str;

int firstPos;
int count = 0;   
bool check = true;
int length = 0;

int main ()
{
    getline(std::cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (check == true)
        {
            if (str[i] != ' ')
            {
                length += 1;
                check = false;
            }
        }
        else
        {
            if (str[i] != ' ')
            {
                length += 1;
            }
            else if (str[i] == ' ')
            {
                count += 1;
                length = 0;
                check = true;
            }
        }
    }

    if (length != 0)
    {
        count += 1;
    }

    std::cout << count;

    length = 0;
    check = true;

    //----------------------------------------

    for (int i = 0; i < str.length(); i++)
    {
        if (check == true)
        {
            if (str[i] != ' ')
            {
                firstPos = i;
                length += 1;
                check = false;
            }
        }
        else
        {
            if (str[i] != ' ')
            {
                length += 1;
            }
            else if (str[i] == ' ')
            {
                std::cout << '\n' << str.substr(firstPos, length);

                length = 0;
                check = true;
            }
        }
    }

    std::cout << '\n' << str.substr(firstPos, length);

}