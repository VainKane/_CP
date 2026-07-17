#include <bits/stdc++.h>

using namespace std;

string str;
char res = '0';

int main()
{
    getline(cin, str);

    for (char value : str)
    {
        if (value > res)
        {
            res = value;
        }
    }

    cout << res;
}