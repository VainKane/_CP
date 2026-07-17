#include <bits/stdc++.h>

using namespace std;

int minp[(int)1e6 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    minp[0] = minp[1] = 1;

    for (int i = 2; i <= 1e3; i++)
    {
        if (minp[i] == 0)
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                if (minp[j] == 0)
                {
                    minp[j] = i;
                }
            }

            minp[i] = i;
        }
    }

    int n;
    while (cin >> n)
    {
        cout << "Min Prime of " << n << " is: " << minp[n] << '\n';
    }

    return 0;
}