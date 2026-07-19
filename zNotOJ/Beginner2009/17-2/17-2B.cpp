#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int const maxLog = 18;

int n;
int m;

long long a[N];
long long st[N][maxLog];
int lg[N];

long long GetMin(int l, int r)
{   
    int k = lg[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int Search(int l, int r, long long x)
{
    int res = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] <= x)
        {
            res = mid;
            r = mid - 1;
        }
        else if (GetMin(l, mid - 1) <= x && l <= mid - 1) 
        {
            if (l == mid - 1) res = l;
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("17-2B.inp", "r", stdin);
    // freopen("17-2B.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        st[i][0] = a[i];
    }

    lg[1] = 0;
    for (int i = 2; i <= n; i++)
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
        long long t;
        int l, r;

        cin >> t >> l >> r;

        int k = Search(l, r, t);
        while (k != -1 && k <= r && t >= a[k])
        {
            t %= a[k];
            k = Search(k + 1, r, t);
        }

        cout << t << '\n';
    }

    return 0;
}