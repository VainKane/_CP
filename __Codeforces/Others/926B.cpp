#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n;
int a[N], b[N];

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);
    FOR(i, 1, n - 1) b[i] = a[i + 1] - a[i];

    int gcd = b[1];
    FOR(i, 2, n - 1) gcd = GCD(gcd, b[i]);

    int res = 0;
    FOR(i, 1, n - 1) res += b[i] / gcd - 1; 
    cout << res;

    return 0;
}