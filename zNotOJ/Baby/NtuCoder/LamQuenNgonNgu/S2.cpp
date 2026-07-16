#include <bits/stdc++.h>

using namespace std;

string str;
char target;

int cnt = 0;

int main()
{
    getline(cin, str);
    cin >> target;

    for (char chr : str)
    {
        if (chr == target)
        {
            cnt++;
        }
    }

    cout << cnt;
}