#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct FenwickTree
{
    vector<vector<long long>> bit[4];
    int m, n;

    FenwickTree(int _m = 0, int _n = 0)
    {
        m = _m, n = _n;
        REP(i, 4) bit[i].assign(m + 5, vector<long long> (n + 5, 0));
    }

    void Update(int x, int y, long long val)
    {
        for (int i = x; i <= m; i += i & -i) for (int j = y; j <= n; j += j & -j)
        {
            bit[0][i][j] += val;
            bit[1][i][j] += 1LL * x * val;
            bit[2][i][j] += 1LL * y * val;
            bit[3][i][j] += 1LL * x * y * val;
        }
    }

    void Update(int x, int y, int u, int v, int val)
    {
        Update(x, y, val);
        Update(x, v + 1, -val);
        Update(u + 1, y, -val);
        Update(u + 1, v + 1, val);
    }

    long long Get(int x, int y)
    {
        long long res = 0;

        for (int i = x; i; i ^= i & -i) for (int j = y; j; j ^= j & -j)
            res += 1LL * (x + 1) * (y + 1) * bit[0][i][j] - 1LL * (y + 1) * bit[1][i][j] 
                - 1LL * (x + 1) * bit[2][i][j] + bit[3][i][j];
        
        return res;
    }

    long long Get(int x, int y, int u, int v)
    {
        return Get(u, v) - Get(x - 1, v) - Get(u, y - 1) + Get(x - 1, y - 1); 
    }
};

int m, n, q;
FenwickTree bit;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> q;
    bit = FenwickTree(m, n);

    FOR(i, 1, m) FOR(j, 1, n)
    {
        int x; cin >> x;
        bit.Update(i, j, i, j, x);
    }

    while (q--)
    {
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1 >> x2 >> y2;

        if (type == 1)
        {
            int val; cin >> val;
            bit.Update(x1, y1, x2, y2, val);
        }
        else cout << bit.Get(x1, y1, x2, y2) << '\n';
    }

    return 0;
}