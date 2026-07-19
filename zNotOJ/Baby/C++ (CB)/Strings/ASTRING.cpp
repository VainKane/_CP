#include <bits/stdc++.h>

std::string Reverse(std::string str);


std::string str;

int main()
{
    getline(std::cin, str);

    std::cout << Reverse(str);

}

std::string Reverse(std::string str)
{
    std::string reversedString = "";

    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversedString += str[i];
    }

    return reversedString;
}
