#include <bits/stdc++.h>

using namespace std;

#define name "BAI1"

long long n, a, b;

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> a >> b;
    cout << max(0ll, a - b) << ' ';

    if (b <= n - a) cout << a;
    else cout << a - (b - (n - a));
}