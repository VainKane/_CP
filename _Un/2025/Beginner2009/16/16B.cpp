#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int const maxLog = 17;

int n;
int d;

int h[N];
int lg[N];
int st[N][maxLog];

int SearchLeft(int &pos)
{
    int l = 1;
    int r = pos;

    int res = pos;
    
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int k = lg[pos - mid + 1];

        if (max(st[mid][k], st[pos - (1 << k) + 1][k]) <= h[pos] + d)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return res;
}

int SearchRight(int &pos)
{
    int l = pos;
    int r = n;

    int res = pos;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        int k = lg[mid - pos + 1];
        if (max(st[pos][k], st[mid - (1 << k) + 1][k]) <= h[pos] + d)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("16B.inp", "r", stdin);
    // freopen("16B.out", "w", stdout);

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
        int a = SearchLeft(i);
        int b = SearchRight(i);
        cout << SearchRight(i) - SearchLeft(i) + 1 << ' ';
    }

    return 0;
}