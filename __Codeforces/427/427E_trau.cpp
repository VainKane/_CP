#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
long long const oo = 1e18;

int n, m;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    long long res = oo;

    FOR(i, 1, n)
    {
        long long tmp = 0;

        for (int l = 1; l <= i; l += m) tmp += a[i] - a[l];
        for (int r = n; r >= i; r -= m) tmp += a[r] - a[i];

        mini(res, 2 * tmp);
    }

    cout << res;
    
    return 0;
}