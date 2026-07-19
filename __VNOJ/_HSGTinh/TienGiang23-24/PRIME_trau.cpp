#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;

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
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res += isPrime(i);
            if (i * i != x) res += isPrime(x / i);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int k = Count(a[i]);
        if (ma < k)
        {
            ma = k;
            res = a[i];
        }
    }

    cout << res;

    return 0;
}