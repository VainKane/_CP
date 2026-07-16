#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = (char)('A' + str[i] - 'a');
        }
    }

    cout << str;
}