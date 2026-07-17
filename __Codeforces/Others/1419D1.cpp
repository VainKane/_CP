#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)1e5 + 10];

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

    int x = (n - 1) / 2;

    int j = x;

    cout << x << '\n' << a[x] << ' ';

    for (int i = 0; i < x; i++)
    {
        cout << a[i] << ' ' << a[x + i + 1] << ' ';
        j += 2;
    }

    if (n % 2 == 0) cout << a[n - 1];

    return 0;
}