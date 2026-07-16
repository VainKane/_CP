#include <bits/stdc++.h>

using namespace std;

int n;
int x[109];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;

        for (int j = 0; j < i; j++)
        {
            if (x[j] > x[i])
            {
                cnt++;
            }
        }

        cout << cnt << ' ';
    }

    return 0;
}