#include <bits/stdc++.h>

using namespace std;

string str;

string letters[30];

int main()
{
    getline(cin, str);

    for (char chr : str)
    {
        letters[chr - 'a'] += chr;
    }

    for (int i = 0; i < 27; i++)
    {
        cout << letters[i];
    }
    return 0;
}
