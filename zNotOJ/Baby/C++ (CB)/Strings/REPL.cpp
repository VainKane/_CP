#include <bits/stdc++.h>

void Replace(std::string str1, std::string str2, std::string &str);


std::string str1;
std::string str2;
std::string str;

int main()
{
    getline(std::cin, str1);
    getline(std::cin, str2);
    getline(std::cin, str);

    Replace(str1, str2, str);

    std::cout << str;
}

void Replace(std::string str1, std::string str2, std::string &str)
{
    std::string s;
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        s = str.substr(i, str1.length());

        if (s == str1)
        {
            count = 0;

            str.erase(i, str1.length());
            str.insert(i, str2);
        }
    }
}