#include <bits/stdc++.h>

using namespace std;

int n;
string str;

int main()
{
    cin >> n;

    while (n--)
    {
        cin >> str;

        if (str.length() >= 11) cout << str[0] << str.length() - 2 << str[str.length() - 1] << '\n';
        else cout << str << '\n';
    }

    return 0;
}