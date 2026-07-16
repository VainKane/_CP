#include <bits/stdc++.h>

using namespace std;

string str;
int cnt = 0;

bool isStart = false;

int main()
{
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            isStart = true;
        }
        if (i == str.length() - 1 && str[i] != ' ')
        {
            cnt++;
        }
        if (str[i] == ' ' && isStart == true)
        {
            cnt++;
            isStart = false;
        }
    }

    cout << cnt;
}