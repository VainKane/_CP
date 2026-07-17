#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

long long a[59];
int tmp[59];

int t;
int n;

long long res = 0;
long long sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        res = LONG_LONG_MIN;

        for (int i = 0; i < n; i++) cin >> a[i];

        int k = n;

        for (int j = 0; j < k; j++)
        {
            sum = 0;

            for (int i = 0; i < n; i++) sum += a[i];

            res = max(res, sum);
            if (j > 0) res = max(res, -sum);
            n--;

            for (int i = 0; i < n; i++) a[i] = a[i + 1] - a[i];
        }

        cout << res << '\n';
    }

    return 0;
}