#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int m;

string s[59];

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        int i = 0;
        int l = 0;
        int cnt = 0;

        while (l < m && i < n)
        {
            if (l + s[i].length() <= m)
            {
                l += s[i].length();
                cnt++;
            }
            else break;
            i++;
        }

        cout << cnt << '\n';
    }

    return 0;
}