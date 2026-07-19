#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

int t;

int a;
int b;
int c;

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;

        res = 0;

        for (int x = 0; x <= 5; x++)
        {
            for (int y = 0; y <= 5; y++)
            {
                for (int z = 0; z <= 5; z++)
                {
                    if (x + y + z <= 5)
                    {
                        res = max(res, (a + x) * (b + y) * (c + z));
                    }
                }
            }
        }
        cout << res << '\n';
    }


    return 0;
}