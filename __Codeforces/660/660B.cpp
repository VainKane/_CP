#include <bits/stdc++.h>

using namespace std;

int const N = 209;

int n, m;
int a[5][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= 2 * n - 1; i += 2)
    {
        a[1][i] = i + 2 * n;
        a[2][i] = i;
        a[3][i] = i + 2 * n + 1;
        a[4][i] = i + 1;
    }

    for (int i = 1; i <= 2 * n - 1; i += 2)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (a[j][i] <= m) cout << a[j][i] << ' ';
        }
    }

    return 0;
}