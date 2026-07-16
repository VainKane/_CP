#include <bits/stdc++.h>

using namespace std;

int n;
int s;

int a[59];
int dp[(int)5e7 + 10];

bool Check(int x)
{
    int sum = 0;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (sum + a[i] <= x)
        {
            sum += a[i];
        }
        else if (a[i] <= x)
        {
            k++;
            sum = a[i];
        }
        else return false;

        if (k > s + 1) return false;
    }

    return true;
}

int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("12F.inp", "r", stdin);
    // freopen("12F.out", "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }

    int l = 0;
    int r = sum;
    int res;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (Check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}