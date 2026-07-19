#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int a[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    while (m--)
    {
        int val;
        cin >> val;

        cout << upper_bound(a, a + n, val) - lower_bound(a, a + n, val) << '\n';
    }

    return 0;
}
