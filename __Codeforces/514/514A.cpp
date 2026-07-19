#include <bits/stdc++.h>

using namespace std;

string Invert(string x)
{
    if (x == "9") return "9";

    string res = "";

    for (int i = 0; i < x.length(); i++)
    {
        int digit = x[i] - '0';

        if (9 - digit < digit)
        {
            res += (char)('0' + 9 - digit);
        }
        else
        {
            res += (char)('0' + digit);
        }
    }

    if (res[0] == '0') res[0] = '9';

    return res;
}

string x;

int main()
{
    cin >> x;
    cout << Invert(x);
    return 0;
}