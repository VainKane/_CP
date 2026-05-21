#include <bits/stdc++.h>

using namespace std;

#define name "weather"

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

string s;
string a[9] = {"gspvhcute", "NW", "WS", "SE", "EN"};

int dp[N];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    s = " " + s;
    int n = s.size() - 1;

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        Add(dp[i], dp[i - 1]);

        string str = "";
        str += s[i - 1];
        str += s[i];

        for (int j = 1; j <= 4; j++)
        {
            if (str != a[j]) continue;
            Add(dp[i], dp[i - 2]);
        }
    }

    cout << dp[n];
}