#include <bits/stdc++.h>

using namespace std;

string s;

void Solve()
{
    s = " " + s + " ";
    int n = s.size() - 1;

    string m = "";

    for (int i = 1; i <= n; i++)
    {
        if (isdigit(s[i])) 
        {
            m += s[i];
        }
        else if (isdigit(s[i - 1]))
        {
            cout << m << ' ';
            m = "";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    Solve();

    return 0;
}