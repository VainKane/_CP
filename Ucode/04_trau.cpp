#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 5e5 + 5;

int n, q;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    while (q--)
    {
        int x; cin >> x;

        long long res = 0;
        FOR(i, 1, n) a[i] += x, res += abs(a[i]);
        cout << res << '\n';
    }

    return 0;
}