#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

int a[N];
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
        t[v] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    Build(2 * v, l, mid);
    Build(2 * v + 1, mid + 1, r);

    t[v] = max(t[2 * v], t[2 * v + 1]);
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

    Push(v);
    int mid = l + (r - l) / 2;
    Update(2 * v, l, mid, left, right, val);
    Update(2 * v + 1, mid + 1, r, left, right, val);

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int Lower(int v, int l, int r, int left, int right, int x)
{
    if (l > right || r < left || t[v] < x) return -1;
    if (l == r) return l;

    Push(v);
    int mid = l + (r - l) / 2;
    int pos = Lower(2 * v, l, mid, left, right, x);
    if (pos != -1) return pos;
    return Lower(2 * v + 1, mid + 1, r, left, right, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("32B.inp", "r", stdin);
    // freopen("32B.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    Build(1, 1, n);

    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;

        int ind = Lower(1, 1, n, 1, n, x);
        if (ind == -1) 
        {
            cout << 0 << '\n';
            continue;
        }

        int k = n - ind + 1;
        Update(1, 1, n, ind, n, -1);

        cout << k << '\n';
    }

    return 0;
}