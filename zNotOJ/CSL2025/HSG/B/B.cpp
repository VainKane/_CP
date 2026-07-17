#include <bits/stdc++.h>

using namespace std;

bool Check1(string str)
{
    bool key = false;
    bool num = false;

    for (char chr : str)
    {
        if (chr >= '0' && chr <= '9')
        {
            num = true;
        }
        if (chr >= 'A' && chr <= 'Z')
        {
            key = true;
        }
    }

    if (key && num)
    {
        return true;
    }

    return false;
}

bool Check2(string str)
{
    int con = 0;

    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        con++;
    }
    if (str[str.length() - 1] >= '0' && str[str.length() - 1] <= '9')
    {
        con++;
    }

    if (con == 2)
    {
        return true;
    }

    return false;
}

bool Check3(string str)
{
    for (int i = 0; i + 1 < str.length(); i++)
    {
        if (str[i] >= '0' && str[i + 1] >= 0 && str[i] <= '9' && str[i + 1] <= '9')
        {
            return false;
        }
        if (str[i] >= 'A' && str[i + 1] >= 'A' && str[i] <= 'Z' && str[i + 1] <= 'Z')
        {
            return false;
        }
    }

    return true;
}

int sum = 0;
int t;
string str;

int main()
{
    cin >> t;
    cin.ignore();

    while (t--)
    {
        getline(cin, str);

        sum = Check1(str) + Check2(str) + Check3(str);

        if (sum == 3) cout << "PERFECT\n";
        else if (sum == 2) cout << "VALID\n";
        else cout << "INVALID\n";
    }

    return 0;
}
