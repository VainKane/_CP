#include <bits/stdc++.h>

using namespace std;

int m;
int n;

int a[15];
int x[15];
int cnt[15];

long double avg;
long double res;

int start = 0;
int k;

void Try(int pos)
{
    if (pos > k)
    {
        long double sum = 0;

        for (int i = 1; i <= m; i++)
        {
            int s = 0;
            for (int j = 1 + start; j <= k + start; j++)
            {
                if (x[j] == i)
                {
                    s += a[j];
                }
            }

            sum += abs(s - avg);
        }

        res = min(res, sum);
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] < 2)
        {
            x[pos + start] = i;
            cnt[i]++;
            Try(pos + 1);
            cnt[i]--;
        }

        if (cnt[i] == 0)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(5);

    while (cin >> m)
    {
        cin >> n;

        avg = 0;
        res = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            avg += a[i];
        }

        avg /= m;
        k = min(n, 2 * m);

        Try(1);

        if (2 * m < n)
        {
            while (start + 2 * m - 1 < n)
            {
                start++;
                Try(1);
            }
        }
        cout << res << '\n';
    }

    return 0;
}