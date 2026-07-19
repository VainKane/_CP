#include <bits/stdc++.h>

std::string Fix(std::string str);
void FindWords(std::string str);


std::string str;

int main()
{
    getline(std::cin, str);


    FindWords(str);

}

void FindWords(std::string str)
{
    bool check = true;
    int length = 0;
    int firstPos;

    std::string word;

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
                std::cout << Fix(str.substr(firstPos, length)) << ' ';

                length = 0;
                check = true;
            }
        }
    }
    
    std::cout << Fix(str.substr(firstPos, length));
}


std::string Fix(std::string str)
{
    std::string result = str;

    if (str[0] >= 'a' && str[0] <= 'z')
    {
        result[0] = (char)((int)str[0] - 'a' + 'A');
    }

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result[i] = (char)((int)str[i] + 'a' - 'A');
        }
    }

    return result;
}
