#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU1"

int const N = 3e5 + 5;

int n;
int a[N];

int Cost(int x)
{
    int res = 0;
    FOR(i, 1, n) res += (a[i] % x != 0);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int gcd = a[1];
    FOR(i, 2, n) gcd = __gcd(gcd, a[i]);

    int res = n;
    FOR(i, gcd + 1, *max_element(a + 1, a + n + 1)) 
    {
        int c = Cost(i); 
        if (c < n) res = min(res, c);
    } 

    if (res == n) res = -1;
    cout << res;

    return 0;
}