#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        
        if (n == 6)
        {
            cout << "1 1 2 3 1 2\n";
        }
        else
        {
            cout << "1 2 ";
            for (int i = 2; i < n - 2; i++)
            {
                cout << i + 1 << ' ';
            }
            cout << "1 2\n";
        }
    }

    return 0;
}