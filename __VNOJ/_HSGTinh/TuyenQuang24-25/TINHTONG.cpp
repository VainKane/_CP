#include <bits/stdc++.h>

using namespace std;

#define name "TINHTONG"

int const N = 1e6 + 5;

int n;
int a[N];

long long res = 0;

bool Check(int x)
{
    return (x % 10 > (x / 10) % 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (Check(a[i])) res += a[i];
    }

    cout << res;

    return 0;
}