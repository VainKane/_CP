#include <bits/stdc++.h>

using namespace std;

int Count(int n)
{
    int cnt = 0;
    bool isDivisor;

    for (int i = 2; i * i <= n; i++)
    {
        isDivisor = false;
        while (n % i == 0)
        {
            isDivisor = true;
            n /= i;
        }

        if (isDivisor) cnt++;
    }

    if (n != 1) cnt++;
    return cnt;
}

int n;

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (Count(val) > Count(res)) res = val;
    }

    cout << res;

    return 0;
}
