#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "THUGON"

string s;

string Convert(int x)
{
    string res = "";
    while (x)
    {
        res += x % 10 + '0';
        x /= 10;
    }
    reverse(all(res));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r" , stdin);
    freopen(name".out", "w", stdout);

    while (cin >> s)
    {
        string res = "";
        s += " ";

        int l = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1]) l++;
            else
            {
                if (l != 1) res += Convert(l);
                res += s[i - 1];

                l = 1;
            }
        }

        cout << res << '\n';
    }

    return 0;
}