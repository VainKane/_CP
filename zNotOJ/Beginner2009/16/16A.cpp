#include <bits/stdc++.h>

using namespace std;

int const maxLog = 17;
int const N = 1e5 + 10;

int n;
int m;

int a[N];
int lg[N];
int st[N][maxLog];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st[i][0] = a[i];
    }

    lg[1] = 0;
    for (int i = 2; i <= 1e5; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;

        int k = lg[r - l + 1];
        cout << min(st[l][k], st[r - (1 << k) + 1][k]) << '\n';
    }

    return 0;
}