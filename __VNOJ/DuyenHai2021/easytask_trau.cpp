#include <bits/stdc++.h>

using namespace std;

#define name "easytask"

int const N = 1e5 + 5;

int n;
int a[N];
long long p[N];
long long res = -1e18;

bool Check(int x)
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
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];

    for (int l = 1; l <= n; l++)
    {
        if (!Check(l)) continue;
        for (int r = l; r <= n; r++)
        {
            if (!Check(r)) continue;
            res = max(res, p[r] - p[l - 1]);
        }
    }

    cout << res;

    return 0;
}