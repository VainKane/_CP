#include <bits/stdc++.h>

using namespace std;

int n;
int x;
int a[(int)1e4 + 10];
long long cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int k = 0; k < n - 2; k++)
    {
        int l = k + 1;
        int r = n - 1;
        int s;

        while (l < r)
        {
            s = a[l] + a[r] + a[k];

            if (s <= x)
            {
                cnt += 1ll * r - l;
                l++;
            }
            else
            {
                r--;
            }
        }
    }

    cout << cnt;

    return 0;
}