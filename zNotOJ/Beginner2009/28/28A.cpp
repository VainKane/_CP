#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n;
int m;

int bit[N];

void Update(int pos, int val)
{
    while (pos <= n)
    {
        bit[pos] += val;
        pos += (pos & -pos);
    }
}

int GetSum(int pos)
{
    int res = 0;
    while (pos)
    {
        res += bit[pos];
        pos -= (pos & -pos);
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
            int x, d;
            cin >> x >> d;
            Update(x, d);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            cout << GetSum(r) - GetSum(l - 1) << '\n';
        }
    }

    return 0;
}