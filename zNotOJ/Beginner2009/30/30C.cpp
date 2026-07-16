#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int k;

int a[N];
int c[N];
vector<int> b;
int t[N * 4];

int res = 0;

void Update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[v] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if (pos <= mid)
    {
        Update(2 * v, l, mid, pos, val);
    }
    else 
    {
        Update(2 * v + 1, mid + 1, r, pos, val);
    }

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int GetMax(int v, int tl, int tr, int l, int r)
{
    if (tr < l || tl > r) return 0;
    if (l <= tl && r >= tr) return t[v];

    int mid = tl + (tr - tl) / 2;
    int max1 = GetMax(2 * v, tl, mid, l, r);
    int max2 = GetMax(2 * v + 1, mid + 1, tr, l, r);

    return max(max1, max2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("30C.inp", "r", stdin);
    // freopen("30C.out", "w", stdout);

    cin >> n >> k;

    b.push_back(0);
    
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int m = b.size() - 1;

    for (int i = 1; i <= n; i++)
    {
        int val = 1;

        auto it = upper_bound(b.begin() + 1, b.end(), a[i] - k);
        if (it != b.end()) val = max(val, GetMax(1, 1, m, 1, it - b.begin() - 1) + 1);

        it = lower_bound(b.begin() + 1, b.end(), a[i] + k);
        if (it != b.end()) val = max(val, GetMax(1, 1, m, it - b.begin(), m) + 1);

        int pos = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        
        Update(1, 1, m, pos, val);
    }

    for (int i = 1; i <= 4 * m; i++) res = max(res, t[i]);
    cout << res;

    return 0;
}