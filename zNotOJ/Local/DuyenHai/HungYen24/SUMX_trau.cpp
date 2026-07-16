#include <bits/stdc++.h>

using namespace std;

#define name "SUMX"

int const N = 1e5 + 5;

int n, x;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> x;

    long long res = 0;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) res += (a[i] + a[j] == x);
    cout << res;
    // cerr << res << '\n';

    return 0;
}