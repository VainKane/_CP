#include <bits/stdc++.h>

using namespace std;

int k;
string str;
string res = "";

int main()
{
    cin >> k;
    cin.ignore();

    getline(cin, str);

    for (char chr : str)
    {
        if (chr - k >= 'a')
        {
            res += (char)(chr - k);
        }
        else
        {
            res += (char)(chr + 'z' - 'a' - k + 1);
        }
    }

    cout << res;
}