#include <bits/stdc++.h>

using namespace std;

#define name "BAI02"

int const N = 100000;

int n;
int a[N];

int res = 0;
int ma = 0;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int Count(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (isPrime(a[i]) && a[i] > ma)
        {
            ma = a[i];
            res = Count(a[i]);
        }
    }

    cout << res;
    cerr << res << '\n';

    return 0;
}