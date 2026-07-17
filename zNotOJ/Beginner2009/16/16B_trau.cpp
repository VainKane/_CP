#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int const maxLog = 17;

int n;
int d;

int h[N];
int lg[N];
int st[N][maxLog];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("16B.inp", "r", stdin);
    freopen("16B.ans", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; i++) 
    {
        cin >> h[i];
        st[i][0] = h[i];
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
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        int r = i;

        int k = lg[i - (l - 1) + 1];
        while (l - 1 >= 1 && max(st[l - 1][k], st[i - (1 << k) + 1][k]) <= h[i] + d) l--;
        k = lg[r + 1 - i + 1];
        while (r + 1 <= n && max(st[i][k], st[r + 1 - (1 << k) + 1][k]) <= h[i] + d) r++;

        cout << r - l + 1 << ' ';
    }

    return 0;
}