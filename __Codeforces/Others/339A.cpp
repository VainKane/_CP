#include <bits/stdc++.h>

using namespace std;

string str;

int cnt[4];
int p = 0;

int main()
{
    cin >> str;

    for (char chr : str)
    {
        if (chr != '+') cnt[chr - '0']++;
        else p++;
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            cout << (char)(i + '0');
            if (p > 0)
            {
                cout << '+'; 
                p--;
            }
        }
    }

    return 0;
}