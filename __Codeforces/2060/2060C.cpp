#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int k;

int a[(int)2e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        for (int i = 0; i < n; i++) cout << a[i] << ' ';
    }

    return 0;
}