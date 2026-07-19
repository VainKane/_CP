#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        cnt = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i + j == n) 
                {
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}