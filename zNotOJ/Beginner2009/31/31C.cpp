#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;
int z;

int t[4 * N];
int lz[4 * N];

void Push(int v)
{
    if (lz[v])
    {
        t[2 * v] += lz[v];
        t[2 * v + 1] += lz[v];
        lz[2 * v] += lz[v];
        lz[2 * v + 1] += lz[v];

        lz[v] = 0;
    }
}

void Build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = m;
        return;
    }

    int mid = l + (r - l) / 2;
    Build(2 * v, l, mid);
    Build(2 * v + 1, mid + 1, r);

    t[v] = t[2 * v];
}

void Update(int v, int l, int r, int left, int right, int val)
{
    if (l > right || r < left) return;
    if (left <= l && right >= r)
    {
        t[v] += val;
        lz[v] += val;
        return;
    }

    int mid = l + (r - l) / 2;
    Push(v);
    Update(2 * v, l, mid, left, right, val);
    Update(2 * v + 1, mid + 1, r, left, right, val);

    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int GetMin(int v, int l, int r, int left, int right)
{
    if (l > right || r < left) return 2e9;
    if (left <= l && right >= r) return t[v];

    int mid = l + (r - l) / 2;
    Push(v);
    int min1 = GetMin(2 * v, l, mid, left, right);
    int min2 = GetMin(2 * v + 1, mid + 1, r, left, right);

    return min(min1, min2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> z;
    Build(1, 1, n);

    while (z--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        v--;

        if (GetMin(1, 1, n - 1, u, v) >= w)
        {
            Update(1, 1, n - 1, u, v, -1 * w);
            cout << "T\n";
        }
        else
        {
            cout << "N\n";
        }
    }

    return 0;
}