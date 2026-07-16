#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        int d = k / (n - 1);

        if (k % (n - 1)) cout << 1LL * d * n + k - d * (n - 1) << '\n';
        else cout << 1LL * (d - 1) * n + (n - 1) << '\n';
    }

    return 0;
}