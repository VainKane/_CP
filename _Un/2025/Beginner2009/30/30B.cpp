#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;

int n;
int m;

int a[N];
int tmin[4 * N];
int tmax[4 * N];

int pos[N];

void Build(int v, int l, int r)
{
    if (l == r)
    {
        tmin[v] = pos[l];
        tmax[v] = pos[l];
    }
    else
    {
        int mid = l + (r - l) / 2;

        Build(2 * v, l, mid);
        Build(2 * v + 1, mid + 1, r);

        tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
        tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        tmin[v] = val;
        tmax[v] = val;
    }
    else
    {
        int mid = l + (r - l) / 2;

        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
        tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
    }
}

int GetMin(int v, int tl, int tr, int l, int r)
{
    if (l > r) return 1e9;
    if (tl == l && tr == r)
    {
        return tmin[v];
    }
    else
    {
        int mid = tl + (tr - tl) / 2;

        int min1 = GetMin(2 * v, tl, mid, l, min(mid, r));
        int min2 = GetMin(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);

        return min(min1, min2);
    }
}

int GetMax(int v, int tl, int tr, int l, int r)
{
    if (l > r) return 0;
    if (tl == l && tr == r)
    {
        return tmax[v];
    }
    else
    {
        int mid = tl + (tr - tl) / 2;

        int max1 = GetMax(2 * v, tl, mid, l, min(mid, r));
        int max2 = GetMax(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);

        return max(max1, max2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("30B.inp", "r", stdin);
    // freopen("30B.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    Build(1, 1, n);

    while (m--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x, y;
            cin >> x >> y;

            int u = pos[a[x]];
            int v = pos[a[y]];

            pos[a[x]] = v;
            pos[a[y]] = u;

            Update(1, 1, n, a[x], v);
            Update(1, 1, n, a[y], u);

            swap(a[x], a[y]);
        }
        else
        {   
            int l, r;
            cin >> l >> r;

            if (GetMax(1, 1, n, l, r) - GetMin(1, 1, n, l, r) == r - l)
            {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }

    return 0;
}