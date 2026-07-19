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

struct SegmentTree
{
    vector<int> t;
    int n;

    SegmentTree (int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
    }

    void Update(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 1e9;
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        int m1 = Get(2 * v, l, mid, left, right);
        int m2 = Get(2 * v + 1, mid + 1, r, left, right);

        return min(m1, m2);
    }

    void Update(int pos, int val)
    {
        Update(1, 1, n, pos, val);
    }

    int Get(int l, int r)
    {
        if (l > r) return 1e9;
        return Get(1, 1, n, l, r);
    }
};

struct Query
{
    int x1, y1, y2, i;
};

int const N = 1e5 + 5;

int m, n, k, q;

vector<int> posR[N], posC[N];
vector<Query> qrR[N], qrC[N]; 
bool okR[N], okC[N];

SegmentTree it;

void Solve(vector<Query> qr[], vector<int> pos[], bool ok[], int m, int n)
{
    it = SegmentTree(n);

    FOR(x2, 1, m)
    {
        for (auto &y : pos[x2]) it.Update(y, x2);
        for (auto &query : qr[x2]) ok[query.i] = it.Get(query.y1, query.y2) >= query.x1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k >> q;
    
    FOR(i, 1, k)
    {
        int x, y;
        cin >> x >> y;
        posR[x].push_back(y);
        posC[y].push_back(x);
    }

    FOR(i, 1, q)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        qrR[x2].push_back({x1, y1, y2, i});
        qrC[y2].push_back({y1, x1, x2, i});
    }

    Solve(qrR, posR, okR, m, n);
    Solve(qrC, posC, okC, n, m);

    FOR(i, 1, q) cout << (okR[i] | okC[i]) << '\n';

    return 0;
}