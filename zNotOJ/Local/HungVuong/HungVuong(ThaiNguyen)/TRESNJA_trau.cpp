#include <bits/stdc++.h>

using namespace std;

#define name "TRESNJA"

long long A, B;
long long res = 0;

int a[20];

int Count(long long x)
{
    if (x <= 9) return x;

    int n = 0;
    int res = 0;

    while (x)
    {
        a[++n] = x % 10;
        x /= 10;
    }    

    a[n + 1] = -1;

    int l = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        if (a[i] != a[i - 1])
        {
            res += a[i - 1] * l * l;
            l = 1;
        }
        else l++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> A >> B;

    for (long long i = A; i <= B; i++) res += Count(i);
    cout << res;
    // cerr << res << '\n';

    return 0;
}
