#include <bits/stdc++.h>

using namespace std;

int n;
int a[1009];

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    for (int i = 1; i < n; i++)
    {
        res += a[i] - a[i - 1] - 1;
    }

    cout << res;

    return 0;
}