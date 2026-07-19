#include <bits/stdc++.h>

using namespace std;

struct Employee
{
    int l, r;
};

int const N = 1e5 + 5;

int n;
Employee a[N];
Employee b[N];

int dp[N];
long long g[N];
int p[N];
long long t[N];

int res = 0;

bool cmp(Employee a, Employee b)
{
    return a.r < b.r;
}

void Update(int v, int l, int r, int pos, long long val)
{
    if (l == r)
    {
        t[v] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if (pos <= mid) Update(2 * v, l, mid, pos, val);
    else Update(2 * v + 1, mid + 1, r, pos, val);

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

long long GetMax(int v, int l, int r, int left, int right)
{
    if (r < left || l > right) return -1e10;
    if (left <= l && right >= r) return t[v];

    int mid = l + (r - l) / 2;
    long long max1 = GetMax(2 * v, l, mid, left, right);
    long long max2 = GetMax(2 * v + 1, mid + 1, r, left, right);

    return max(max1, max2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + n + 1, cmp);
    
    for (int i = 1; i <= n; i++)
    {
        b[i] = {i, a[i].r};
    }

    for (int i = 1; i <= n; i++)
    {
        auto it = upper_bound(b + 1, b + n + 1, Employee {0, a[i].l}, cmp);
        Employee e = *(it - 1);
        int k = e.l;

        dp[i] = p[k] + a[i].r - a[i].l;
        dp[i] = max(1ll * dp[i], GetMax(1, 1, n, k + 1, i - 1) + a[i].l + a[i].r);

        Update(1, 1, n, i, dp[i] - 2ll * a[i].r);
        p[i] = max(p[i - 1], dp[i]);
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}