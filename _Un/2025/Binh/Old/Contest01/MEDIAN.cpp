#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "MEDIAN"

int const N = 2e5 + 5;

int n, k;
pair<int, int> a[N];

struct Node
{
    vector<int> x;

    void Merge(Node a, Node b)
    {
        x.resize(a.x.size() + b.x.size());
        int l = -1, r = -1;
        
        REP(i, x.size())
            x[i] = (r + 1 >= b.x.size() || l + 1 < a.x.size() && a.x[l + 1] < b.x[r + 1]) ? a.x[++l] : b.x[++r];
    }
};

struct SegmentTree
{
    vector<Node> t;
    int n = 0, med = 0;

    void Build(int v, int l, int r)
    {
        if (l == r)
        {
            t[v].x.push_back(a[l].S);
            return;
        }

        int mid = (l + r) / 2;
        Build(2 * v, l, mid);
        Build(2 * v + 1, mid + 1, r);

        t[v].Merge(t[2 * v], t[2 * v + 1]);
    }

    SegmentTree(int _n, int _k)
    {
        n = _n;
        med = (_k + 1) / 2;
        
        t.resize(4 * n + 5);
        Build(1, 1, n);        
    }

    int Get(int v, int l, int r, int left, int right, int k)
    {
        if (l == r) return a[l].F;

        int mid = (l + r) / 2;
        auto it1 = lower_bound(all(t[2 * v].x), left);
        auto it2 = upper_bound(all(t[2 * v].x), right);

        if (it2 - it1 >= k) return Get(2 * v, l, mid, left, right, k);
        return Get(2 * v + 1, mid + 1, r, left, right, k - (it2 - it1));
    }

    int Get(int l, int r)
    {
        return Get(1, 1, n, l, r, med);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        a[i] = {x, i};
    }

    sort(a + 1, a + n + 1);

    SegmentTree it(n, k);
    FOR(i, 1, n - k + 1) cout << it.Get(i, i + k - 1) << ' ';
   
    return 0;
}