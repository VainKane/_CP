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
        s.erase(s.length() - 2, 2);

        s += 'i';

        cout << s <<'\n';
    }

    return 0;
}