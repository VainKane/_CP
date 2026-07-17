#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int Solve()
{
    int res = 1;

    for (int i = 1; i <= n; i++)
    {
        int l = i - 1;
        int r = i + 1;

        while (s[l] == s[r] && l >= 1 && r <= n)
        {
            l--;
            r++;
        }

        res = max(res, r - l - 1);

        if (s[i] != s[i - 1]) continue;
        l = i - 2;
        r = i + 1;

        while (s[l] == s[r] && l >= 1 && r <= n)
        {
            l--;
            r++;
        }

        res = max(res, r - l - 1);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;
    s = " " + s;

    cout << Solve();

    return 0;
}