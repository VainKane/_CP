#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n, k, x;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k >> x;
        FOR(i, 1, n) cin >> a[i];

        sort(a + 1, a + n + 1);

        int res = 0;
        FOR(i, 1, n - 1) maxi(res, (a[i + 1] - a[i]) / 2);
        maxi(res, max(a[1], x - a[n]));

        cout << res << '\n';
    }

    return 0;
}