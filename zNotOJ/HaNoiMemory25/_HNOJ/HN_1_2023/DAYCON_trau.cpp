#include <bits/stdc++.h>

using namespace std;

#define name "DAYCON"

int const N = 1e6 + 5;

int n;
int a[N];

int res = 1e9;

bool isPrime(int x)
{
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
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
        for (int j = i + 1; j <= n; j++)
        {
            int cnt = 0;
            for (int k = i; k <= j; k++) cnt += isPrime(a[k]);
            
            if (cnt >= 2) res = min(res, j - i + 1);
        }
    }

    if (res == 1e9) res = -1;

    cout << res;
    cerr << res << '\n';

    return 0;
}