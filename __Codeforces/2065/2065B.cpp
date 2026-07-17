#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s;

        int n = s.length();

        while (n--)
        {
            for (int i = 0; i < s.length() - 1 && s.length() > 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    if (i == 0 && s.length() >= 3)
                    {
                        s[i] = s[i + 2];
                    }
                    else if (i != 0)
                    {
                        s[i] = s[i - 1];
                    }

                    s.erase(i + 1, 1);
                }
            }
        }

        cout << s.length() << '\n';
    }

    return 0;
}