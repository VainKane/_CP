#include <bits/stdc++.h>

using namespace std;

int n;
string a[109];
int res = 0;

int length = 1;

int main()
{
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        string str = a[i];
        length = 1;

        for (int j = 0; j + 1 < str.length(); j++)
        {
            if (str[j] == str[j + 1])
            {
                length++;
            }
            else
            {
                if (res < length)
                {
                    res = length;
                }

                length = 1;
            }
        }
    }

    if (res < length)
    {
        res = length;
    }

    cout << res;
}