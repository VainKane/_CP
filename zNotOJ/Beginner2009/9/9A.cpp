#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)5e4 + 10];
int q;
int x;

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

    cin >> q;

    while (q--)
    {
        cin >> x;
        
        int l = 0;
        int r = n - 1;
        int s;

        int cnt = 0;

        while (l <= r)
        {
            s = a[l] + a[r];

            if (s <= x)
            {
                cnt += r - l;
                l++;
            }
            else
            {
                r--;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}