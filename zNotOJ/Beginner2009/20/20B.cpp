#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 10;

int n;
int m;

int parent[N];
int res[N];

void MakeSet()
{
    for (int i = 1; i <= n + 1; i++)
    {
        parent[i] = i;
    }
}

int Find(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("20B.inp", "r", stdin);
    // freopen("20B.out", "w", stdout);

    cin >> n >> m;

    MakeSet();
    while (m--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        int i = Find(l);
        while (i <= x - 1)
        {
            res[i] = x;
            parent[i] = Find(i + 1);
            i = Find(parent[i]);
        }
        i = Find(x + 1);
        while (i <= r)
        {
            res[i] = x;
            parent[i] = Find(i + 1);
            i = Find(parent[i]);
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << ' ';

    return 0;
}