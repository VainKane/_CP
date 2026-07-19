#include <bits/stdc++.h>

using namespace std;

int q[109];

string str;

int cnt = 0;

int main()
{
    getline(cin, str);

    if (str[0] == 'Q') q[0] = 1;

    for (int i = 1; i < str.length(); i++)
    {
        q[i] = q[i - 1];
        if (str[i] == 'Q') q[i]++;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A')
        {
            cnt += q[i - 1] * (q[str.length() - 1] - q[i]);
        }
    }

    cout << cnt;

    return 0;
}