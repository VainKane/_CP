#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n;
int a[N];
vector<int> b;

int t[4 * N];

int trace[N];

void Update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[v] = max(t[v], val);
        return;
    }

    int mid = l + (r - l) / 2;
    if (pos <= mid) Update(2 * v, l, mid, pos, val);
    else Update(2 * v + 1, mid + 1, r, pos, val);

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int GetMax(int v, int l, int r, int left, int right)
{
    if (l > right || r < left) return -1e9;
    if (l >= left && r <= right) return t[v];

    int mid = l + (r - l) / 2;
    int max1 = GetMax(2 * v, l, mid, left, right);
    int max2 = GetMax(2 * v + 1, mid + 1, r, left, right);

    return max(max1, max2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

    Update(1, 1, n, a[1], 1);

    for (int i = 2; i <= n; i++)
    {
        int val = GetMax(1, 1, n, 1, a[i] - 1) + 1;
        Update(1, 1, n, a[i], val);
    }

    cout << t[1];

    return 0;
}