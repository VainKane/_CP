#include <bits/stdc++.h>

using namespace std;

int t;

string a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> a;

        string res = "";

        for (char key : a)
        {
            if (key == 'p') res += 'q';
            else if (key == 'q') res += 'p';
            else res += 'w';
        }

        for (int i = res.length() - 1; i >= 0; i--) cout << res[i];
        
        cout << '\n';
    }

    return 0;
}