#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define sz(v) ((int)v.size())

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct Node
{
    long long x[2][2];

    Node()
    {
        memset(x, 0, sizeof x);
    }
};

struct SegmentTree
{
    vector<Node> t;
    int n;

    Node Merge(Node a, Node b)
    {
        Node res;
        
        FOR(i, 0, 1) FOR(j, 0, 1) FOR(u, 0, 1) FOR(v, 0, 1) if (u + v != 2)
            maxi(res.x[i][j], a.x[i][u] + b.x[v][j]);
    
        return res;
    }

    void Build(int v, int l, int r, int a[])
    {
        if (l == r)
        {
            t[v].x[1][1] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        Build(2 * v, l, mid, a);
        Build(2 * v + 1, mid + 1, r, a);

        t[v] = Merge(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(int a[] = {}, int _n = 0)
    {
        n = _n;
        t.assign(4 * n, Node());
        if (n) Build(1, 1, n, a);
    }  

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v].x[1][1] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = Merge(t[2 * v], t[2 * v + 1]);
    }

    void Update(int pos, int val)
    {
        Update(1, 1, n, pos, val);
    }
};

int const N = 4e4 + 5;

int n, d;

int a[N];
SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];

    it = SegmentTree(a, n);

    long long res = 0;

    while (d--)
    {
        int idx, val;
        cin >> idx >> val;
        it.Update(idx, val);
        res += it.t[1].x[1][1];
    }

    cout << res;

    return 0;
}