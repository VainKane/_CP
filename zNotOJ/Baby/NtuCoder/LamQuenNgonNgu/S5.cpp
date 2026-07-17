#include <bits/stdc++.h>

using namespace std;

string Reverse(string str)
{
    string res = "";

    for (int i = str.length() - 1; i >= 0; i--)
    {
        res += str[i];
    }

    return res;
}

string str;

int main()
{
    getline(cin, str);

    if (str == Reverse(str))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}