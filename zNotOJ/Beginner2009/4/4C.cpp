#include <bits/stdc++.h>

using namespace std;

string s;

unordered_set<string> t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j <= s.length() - i; j++)
        {
            t.insert(s.substr(j, i));
        }
    }

    cout << t.size();

    return 0;
}