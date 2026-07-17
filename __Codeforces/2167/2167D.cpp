#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n;
long long a[N];

int Solve()
{
    int res = 101;
    FOR(i, 1, n) FOR(j, 2, 100)
    {
        if (__gcd(a[i], 1ll * j) == 1)
        {
            res = min(res, j);
            break;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        cout << Solve() << '\n';
    }

    return 0;
}