#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "lock"

struct SegmentTree
{
    vector<int> t;
    vector<int> lz;
    int n;
    
    int MOD = 3;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
    }

    void Add(int &x, int const &y)
    {
        x += y;
        if (x >= MOD) x -= MOD;
    }

    void Push(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                Add(t[u], lz[v]);
                Add(lz[u], lz[v]);
            }
            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int &left, int &right)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            Add(t[v], 1);
            Add(lz[v], 1);
            return;
        }

        Push(v);

        int mid = (l + r) >> 1;
        Update(2 * v, l, mid, left, right);
        Update(2 * v + 1, mid + 1, r, left, right);

        t[v] = (t[2 * v] + t[2 * v + 1]) % MOD;
    }

    int Get(int v, int l, int r, int &pos)
    {
        if (l == r) return t[v];

        Push(v);
        int mid = (l + r) >> 1;
        
        if (pos <= mid) return Get(2 * v, l, mid, pos);
        return Get(2 * v + 1, mid + 1, r, pos);
    }

    void Update(int l, int r)
    {
        Update(1, 1, n, l, r);
    }

    int Get(int pos)
    {
        return Get(1, 1, n, pos);
    }
};

SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    int n, t;
    cin >> n >> t;

    it = SegmentTree(n);
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        it.Update(l, r);
    }

    int res = 0;
    FOR(i, 1, n) res += !it.Get(i);
    cout << res;

    return 0;
}