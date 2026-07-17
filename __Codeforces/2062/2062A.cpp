#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> s;

        int cnt = 0;

        for (char num : s) if (num == '0') cnt++;

        cout << s.length() - cnt << '\n';
    }
    return 0;
}