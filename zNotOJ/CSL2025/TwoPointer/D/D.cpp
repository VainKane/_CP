#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int matrix[409][409];

int pre[409][409];
int area[409][409];

int heights[409][409];

int main()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = i;

            while (a < m && matrix[a][j] == 0)
            {
                heights[i][j]++;
                a++;
            }
        }
    }


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int res = 0;
            int r = j + 1;

            for (int h = heights[i][j]; h >= 1; h--)
            {
                while (heights[i][r] >= h)
                {
                    r++;
                }

                if (res < (r - j) * h)
                {
                    res = (r - j) * h;
                }
            }

            cout << res << ' ';
        }

        cout << '\n';
    }

    return 0;
}
