#include <bits/stdc++.h>

using namespace std;

string str;

int cnt = 0;

int main()
{
    getline(cin, str);

    for (char chr : str)
    {
        if (chr >= '0' && chr <= '9')
        {
            cnt++;
        }
    }

    cout << cnt;
}