#include <bits/stdc++.h>

using namespace std;

string str;
int cnt[30];
int res = 0;

int main()
{
    getline(cin, str);

    for (char chr : str)
    {
        cnt[chr - 'a']++;
    }

    for (int i = 0; i <= 29; i++)
    {
        if (cnt[i] > 0)
        {
            res++;
        }
    }

    cout << res;
}