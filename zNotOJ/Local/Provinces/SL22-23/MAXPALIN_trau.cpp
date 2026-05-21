#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int Solve()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            string s1 = "";
            string s2 = "";

            for (int k = i; k <= j; k++)
            {
                s1 += s[k];
                s2 = s[k] + s2;
            }

            if (s1 == s2) res = max(res, j - i + 1);
        }
    }

    return res;
}

int main()
{
    cin >> n >> s;
    s = " " + s;
    int res = Solve();
    cout << res;
    cerr << res << '\n';
}