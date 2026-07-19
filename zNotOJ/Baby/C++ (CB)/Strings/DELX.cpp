#include <iostream>

std::string Delete(std::string str, char x);


std::string str;
char x;

int main()
{
    std::cin >> x;
    std::cin.ignore();

    getline(std::cin, str);

    std::cout << Delete(str, x);
}

std::string Delete(std::string str, char x)
{
    std::string result;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != x)
        {
            result += str[i];
        }
    }

    return result;
}