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
#define name "LISTREE"

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

    SegmentTree(int _n = 0)
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

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;
        int val1 = Get(2 * v, l, mid, left, right);
        int val2 = Get(2 * v + 1, mid + 1, r, left, right);
    
        return max(val1, val2);
    }

    void Update(int pos, int val)
    {
        if (pos < 1 || pos > n) return;
        Update(1, 1, n, pos, val);
    }

    int Get(int l, int r)
    {
        if (l < 1 || r > n || l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};

int const N = 1e5 + 5;

int n;

vector<int> adj[N];
int a[N];

SegmentTree it;

int res[N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    it = SegmentTree(sz(vals));
}

void DFS(int u, int p)
{
    int val = it.Get(a[u], a[u]);
    int tmp = it.Get(1, a[u] - 1) + 1;
   
    res[u] = max(it.t[1], tmp);
    it.Update(a[u], tmp);

    for (auto &v : adj[u]) if (v != p) DFS(v, u);
    it.Update(a[u], val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    FOR(i, 1, n) cin >> a[i];

    Compress();
    DFS(1, -1);

    FOR(u, 2, n) cout << res[u] << ' ';

    return 0;
}