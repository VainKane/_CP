#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            str.erase(i, 1);
            i -= 1;
        }
    }

    cout << str;
}