#include <bits/stdc++.h>

using namespace std;

int t;

int a[(int)1e3 + 10];
int b[(int)1e6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int m = ( n * (n - 1) ) / 2;

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(b, b + m);

        
    }

    return 0;
}