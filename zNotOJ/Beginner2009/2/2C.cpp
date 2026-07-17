#include <bits/stdc++.h>

using namespace std;

int n;

int k = 0;

int a;
int b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int l = 1; l * l + 2 * l - l <= 2 * n; l++)
    {
        if ((2 * n - l * l + l) % (2 * l) == 0)
        {
            if (k < l)
            {
                a = (2 * n - l * l + l) / (2 * l);
                b = l + a - 1;

                k = b - a + 1;
            }
        }
    }

    cout << n << "=" << a << "+...+" << b;

    return 0;
}