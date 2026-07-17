#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

int a[N];
long long t[4 * N];

void Build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;

    Build(2 * v, l, mid);
    Build(2 * v + 1, mid + 1, r);

    t[v] = t[2 * v] + t[2 * v + 1];
}

void Update(int v, int l, int r, int pos, int val)
{
    if (l == r) 
    {
        t[v] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if (pos <= mid) Update(2 * v, l, mid, pos, val);
    else Update(2 * v + 1, mid + 1, r, pos, val);

    t[v] = t[2 * v] + t[2 * v + 1];
}

long long GetSum(int v, int l, int r, int left, int right)
{
    if (l > right || r < left) return 0;
    if (left <= l && right >= r) return t[v];

    int mid = l + (r - l) / 2;
    long long s1 = GetSum(2 * v, l, mid, left, right);
    long long s2 = GetSum(2 * v + 1, mid + 1, r, left, right);

    return s1 + s2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Build(1, 1, n);

    while (m--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) Update(1, 1, n, x, y);
        else cout << GetSum(1, 1, n, x, y) << '\n';
    }

    return 0;
}