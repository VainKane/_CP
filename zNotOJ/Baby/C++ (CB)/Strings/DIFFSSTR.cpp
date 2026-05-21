#include <bits/stdc++.h>

bool Search(std::string strings[], std::string str, int n);
int Solve(std::string strings[], std::string str);


int n;
int l;

std::string str;

std::string strings[105];

int main()
{
    std::cin >> n;
    std::cin.ignore();

    getline(std::cin, str);

    std::cout << Solve(strings, str);
}

int Solve(std::string strings[], std::string str)
{
    int count = 0;
    bool isLength = true;

    for (int l = 1; l <= n; l++)
    {
        count = 0;
        isLength = true;
        strings[0] = str.substr(0, l);

        for (int i = 1; i + l <= str.length(); i++)
        {
            count += 1;

            std::string str1 = str.substr(i, l);

            if (Search(strings, str1, count) == false)
            {
                strings[i] = str1;
            }
            else
            {
                isLength = false;
                break;
            }
        }

        if (isLength == true)
        {
            return l;
        }
    }
}

bool Search(std::string strings[], std::string str, int n)
{
    int length = str.length();

    for (int i = 0; i < n; i++)
    {
        if (strings[i] == str)
        {
            return true;
        }
    }

    return false;
}
