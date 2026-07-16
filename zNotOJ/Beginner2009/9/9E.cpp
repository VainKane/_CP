#include <bits/stdc++.h>

using namespace std;

int n;
int a[7009];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int x = 0; x < n - 2; x++)
    {
        int z1 = x;
        int z2 = x;

        for (int y = x + 1; y < n - 1; y++)
        {
            while (z1 < n && (a[z1] - a[y] < a[y] - a[x])) z1++;
            while (z2 < n && (a[z2] - a[y] <= 2 * (a[y] - a[x]))) z2++;
            z2--;

            if (z2 >= z1) res += z2 - z1 + 1;
        }
    }

    cout << res;
    
    return 0;
}