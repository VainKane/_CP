#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define name "MARIO"

typedef long long ll;

int const N = 1e5 + 5;

int n, x, k;
pii a[N];
ll p[N];

ll res = 0;

bool cmp(pii a, pii b)
{
    return a.F < b.F;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> x >> k;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
    }

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i].S;

    for (int i = 1; i <= n && a[i].F <= x; i++)
    {
        int idx = upper_bound(a + 1, a + n + 1, make_pair(a[i].F + k - (x - a[i].F), 0), cmp) - 1 - a;
        res = max(res, p[idx] - p[i - 1]);
    }

    for (int i = n; i >= 1 && a[i].F >= x; i--)
    {
        int idx = lower_bound(a + 1, a + n + 1, make_pair(a[i].F - (k - (a[i].F - x)), 0), cmp) - a;
        res = max(res, p[i] - p[idx - 1]);
    }

    cout << res;

    return 0;
}