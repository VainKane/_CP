#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n;
int a[N];

void Solve()
{
    bool odd = false, even = false;
    FOR(i, 1, n)
    {
        if (a[i] & 1) odd = true;
        else even = true;
    }

    if (odd && even) sort(a + 1, a + n + 1);
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
        Solve();
        FOR(i, 1, n) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}