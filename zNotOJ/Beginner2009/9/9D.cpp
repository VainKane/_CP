#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[409][409];
int h[409][409];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];

            h[m - 1][j] = abs(a[i][j] - 1);
        } 
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            h[i][j] = h[i + 1][j];

            if (a[i][j] == 0) h[i][j]++;
            else h[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int res = 0;

            for (int height = 1; height <= h[i][j]; height++)
            {
                int k = j;
                while (h[i][k] >= height) k++;
                res = max(res, (k - j) * height); 
            }

            cout << res << ' ';
        }

        cout << '\n';
    }

    return 0;
}