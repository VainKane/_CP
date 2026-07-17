#include <bits/stdc++.h>

using namespace std;

int ToInt(string s)
{
    int res = 0;

    for (char chr : s)
    {
        res *= 10;
        res += chr - '0';
    }

    return res;
}

int Cal(string s, int n)
{
    if (s == "0") return 0;

    int res = ToInt(s.substr(0, s.length() - 1)) + 1;
    if (*s.rbegin() - '0' < n || n == 0) res -= 1;

    int b = 10;

    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (n == 0 && i == 0) continue;

        int a = ToInt(s.substr(0, i)) + 1;
        int digit = s[i] - '0';

        if (i == 0 && n != 0)
        {
            if (digit > n) res += a * b;
            else if (digit == n) res += ToInt(s.substr(i + 1)) + 1;

            b *= 10;
            continue;
        }

        if (n == 0) a -= 1;

        if (digit > n) res += a * b;
        else if (digit == n) res += (a - 1) * b + ToInt(s.substr(i + 1)) + 1; 
        else res += (a - 1) * b;

        b *= 10;
    }

    return res;
}

string a;
string b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> a >> b)
    {
        if (a == "0" && b == "0")
            return 0;

        for (int i = 0; i <= 9; i++)
        {
            cout << Cal(to_string(max(ToInt(a), ToInt(b))), i) - Cal(to_string(min(ToInt(a), ToInt(b)) - 1), i) << ' ';
        }

        cout << '\n';
    }

    return 0;
}