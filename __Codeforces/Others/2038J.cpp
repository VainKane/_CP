#include <bits/stdc++.h>

using namespace std;

int n;

int p = 0;
char event;
int val;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> event >> val;

        if (event == 'B')
        {
            int k = min(p, val);
            val -= k;
            p -= k;

            if (val >= 1)
            {
                cout << "YES\n";
            }
            else 
            {
                cout << "NO\n";
            }
        }
        else 
        {
            p += val;
        }
    }

    return 0;
}