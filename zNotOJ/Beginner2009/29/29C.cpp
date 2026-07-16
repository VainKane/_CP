#include <bits/stdc++.h>

using namespace std;

#define name "29C"

int const N = 1e5 + 5;
int const LOG = 17;

typedef long long ll;

int n;
int m;
int a[N];

int bit[N];

void UpdatePoint(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

void UpdateRange(int l, int r, int val)
{
    UpdatePoint(l, val);
    UpdatePoint(r + 1, -val);
}

int Get(int idx)
{
    int res = 0;  
    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }

    return res;
}

int Lower(int x)
{
    int l = 1;
    int r = n;

    int res = n + 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int p = Get(mid);
        if (Get(mid) >= x)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) UpdatePoint(i, a[i] - a[i - 1]);
    UpdatePoint(1, a[1]);

    cin >> m;
    for (int i = 1; i <= m; i++) 
    {
        int t;
        cin >> t;

        int k = Lower(t);

        UpdateRange(k, n, -1);
        cout << n - k + 1 << '\n';
    }

    return 0;
}