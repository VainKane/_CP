#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

int const N = 1009;

int m, n;
int a[N][N];

FenwickTree bit[N];

bool Check(int &x)
{
    int i = 1;
    int j = n;

    while (i <= m && j)
    {
        int val = a[i][j] + bit[i].Get(j);
        int k = bit[i].Get(j);
        
        if (val == x) return true;
        else if (val > x) j--;
        else i++;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m) bit[i] = FenwickTree(n);

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int x; cin >> x;
            cout << (Check(x) ? "Y\n" : "N\n");
        }
        else 
        {
            int x, y, val;
            cin >> x >> y >> val;

            FOR(i, x, m) bit[i].Update(y, val);
        }
    }

    return 0;
}