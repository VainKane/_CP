#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;

int n;
int m;

long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("17-2B.inp", "r", stdin);
    freopen("17-2B.ans", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (m--)
    {
        long long t;
        int l, r;

        cin >> t >> l >> r;

        for (int i = l; i <= r; i++)
        {
            t %= a[i];
        }

        cout << t << '\n';
    }

    return 0;
}