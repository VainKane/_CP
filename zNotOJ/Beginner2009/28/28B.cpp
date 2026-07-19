#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

int bit[N];

void UpdatePoint(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

void UpdateRange(int l, int r, int val)
{
    UpdatePoint(l, val);
    UpdatePoint(r + 1, -val);
}

int Get(int idx)
{
    int res = 0;
    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }   

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r, d;
            cin >> l >> r >> d;

            UpdateRange(l, r, d);
        }
        else
        {
            int x;
            cin >> x;

            cout << Get(x) << '\n';
        }
    }

    return 0;
}