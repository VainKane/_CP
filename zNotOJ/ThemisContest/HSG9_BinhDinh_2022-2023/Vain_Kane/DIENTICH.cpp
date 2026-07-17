#include <bits/stdc++.h>

using namespace std;

int maxS = 0;

int r;

int main()
{
    cin >> r;

    for (int x = 0; x <= r; x++)
    {
        for (int y = 0; y <= r; y++)
        {
            if (x * x + y * y <= r * r)
            {
                if (x * y > maxS)
                {
                    maxS = x * y;
                }
            }
        }
    }

    cout << maxS * 4;
}
