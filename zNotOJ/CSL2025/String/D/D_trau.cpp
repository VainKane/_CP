#include <bits/stdc++.h>

using namespace std;

bool s[(int)1e4][(int)1e4];

int DP(string str)
{
    int res = 1;

    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        s[i][i] = true;
    }

    int i = 0;
    int j = 1;
    int dig = j;

    while (i < n && j < n)
    {
        if (j - i == 1)
        {
            if (str[i] == str[j])
            {
                s[i][j] = true;

                if (j - i + 1 > res)
                {
                    res = j - i + 1;
                }
            }
        }

        if ((str[i] == str[j]) && s[i + 1][j - 1])
        {
            s[i][j] = true;

            if (j - i + 1 > res)
            {
                res = j - i + 1;
            }
        }

        i++;
        j++;

        if (j == n)
        {
            dig++;
            j = dig;
            i = 0;
        }
    }

    return res;
}

int Solve(string str)
{
    int l;
    int r;
    int res = 0;

    str = " " + str;

    for (int i = 1; i < str.length(); i++)
    {
        l = i - 1;
        r = i + 1;

        while (str[l] == str[r] && l >= 0 && r < str.length())
        {
            if (r - l + 1 > res)
            {
                res = r - l + 1;
            }

            l--;
            r++;
        }

        l = i;
        r = i + 1;

        if (str[i] == str[i + 1])
        {
            if (r - l + 1 > res)
            {
                res = r - l + 1;
            }

            while (str[l] == str[r])
            {
                if (r - l + 1 > res)
                {
                    res = r - l + 1;
                }

                l--;
                r++;
            }
        }
    }

    if (res == 0)
    {
        res = 1;
    }

    return res;
}

string str;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str;
    cout << Solve(str);

    return 0;
}
