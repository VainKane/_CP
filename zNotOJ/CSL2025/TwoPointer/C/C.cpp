#include <bits/stdc++.h>

using namespace std;

int m;
int n;
int k;
int s;

int a[(int)1e5 + 10];
int b[(int)1e5 + 10];

long long sum;

int l;
int r;

int minDiff;


int main()
{
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + m);
    sort(b, b + n);

    while (k--)
    {
        cin >> s;

        l = 0;
        r = n - 1;
        minDiff = INT_MAX;

        while (l < m && r >= 0)
        {
            sum = (long long)a[l] + b[r];

            if (sum == s)
            {
                minDiff = 0;
                r = -1;
            }
            else if (sum < s)
            {
                if (abs(sum - s) < minDiff)
                {
                    minDiff = abs(sum - s);
                }

                l++;
            }
            else
            {
                if (abs(sum - s) < minDiff)
                {
                    minDiff = abs(sum - s);
                }

                r--;
            }
        }

        cout << minDiff << '\n';
    }

    return 0;
}
