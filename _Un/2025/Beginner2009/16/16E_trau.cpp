#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 10;

struct Rope
{
    int l = 0;
    int r = 0;
};

int n;
int k;
Rope a[N];

int p[2 * N];

int res = 1e7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("16E.inp", "r", stdin);
    freopen("16E.ans", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i].l >> a[i].r;
        if (a[i].l > a[i].r) a[i].r += n;

        p[a[i].l] = max(p[a[i].l], a[i].r);
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        p[i] = max(p[i], p[i - 1]);
    }

    for (int i = 1; i <= n; i++)
    {
        int x = i;
        int cnt = 0;
        while (x < n + i)
        {
            int r = p[x];
            if (r < x)
            {
                cnt = 1e7;
                break;
            }
            x = r + 1;
            cnt++;
        }

        res = min(res, cnt);
    }

    if (res == 1e7)
    {
        cout << "impossible";
        return 0;
    }

    cout << res;

    return 0;
}