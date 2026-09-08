#include <bits/stdc++.h>

using namespace std;

int n;

int a[109];
bool t[109];

int x[109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 0;

        for (int j = n; j >= 1; j--)
        {
            if (cnt == a[i] && !t[j])
            {
                t[j] = true;
                x[i] = j;
                break;
            }

            if (!t[j])
            {
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << ' ';
    }

    return 0;
}