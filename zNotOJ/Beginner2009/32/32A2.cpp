#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int q;

int a[N];
int t[4 * N];

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

    t[v] = max(t[2 * v], t[2 * v + 1]);
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

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int Search(int v, int l, int r, int left, int right, int x)
{
    if (l > right || r < left || t[v] < x) return -1;
    if (l == r) return l;
    
    int mid = l + (r - l) / 2;
    
    int pos = Search(2 * v, l, mid, left, right, x);
    if (pos != -1) return pos;
    return Search(2 * v + 1, mid + 1, r, left, right, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Build(1, 1, n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int i, x;
            cin >> i >> x;
            Update(1, 1, n, i, x);
        }
        else
        {
            int u, v, x;
            cin >> u >> v >> x;
            cout << Search(1, 1, n, u, v, x) << '\n';
        }
    }

    return 0;
}