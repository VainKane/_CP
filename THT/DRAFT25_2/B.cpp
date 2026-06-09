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
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define TASKNAME "TASKNAMEGOESHERE"

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

template<typename T> bool mini(T &a, const T &b) {
     return a > b ? a = b, 1 : 0;
}

template<typename T> bool maxi(T &a, const T &b) {
     return a < b ? a = b, 1 : 0;
}

int const N = 2e5 + 5;

struct Node
{
    long long mi, ma, x1, x2;
    long long val[2][2];

    Node()
    {
        memset(val, -1, sizeof val);
    }

    void Add(int x)
    {
        x1 += x, x2 += x;
        mi += x, ma += x;
    }
};

struct SegmentTree
{
    vector<Node> t;
    vector<int> lz;
    int n;

    Node Merge(Node a, Node b)
    {
        Node res;
        if (b.val[0][0] == -1) return a;
        if (a.val[0][0] == -1) return b;
        
        res.mi = min(a.mi, b.mi);
        res.ma = max(a.ma, b.ma);
        res.x1 = a.x1, res.x2 = b.x2;

        REP(i1, 2) REP(j1, 2) REP(i2, 2) REP(j2, 2)
            res.val[i1][j2] = a.val[i1][j1] + b.val[i2][j2] + (j1 | i2 ? 0 : abs(a.x2 - b.x1));

        maxi(res.val[1][1], res.ma - res.mi);
        return res;
    }

    void Build(int v, int l, int r, int a[])
    {
        if (l == r)
        {
            t[v].mi = t[v].ma = t[v].x1 = t[v].x2 = a[l];
            memset(t[v].val, 0, sizeof t[v].val);
            return;
        }

        int mid = (l + r) >> 1;
        Build(v << 1, l, mid, a);
        Build(v << 1 | 1, mid + 1, r, a);

        t[v] = Merge(t[v << 1], t[v << 1 | 1]);
    }

    SegmentTree(int _n = 0, int a[] = {})
    {
        n = _n;
        t.assign(4 * n, Node());
        lz.assign(4 * n, 0);

        if (n) Build(1, 1, n, a);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1)
            {
                t[u].Add(lz[v]);
                lz[u] += lz[v];
            }

            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v].Add(val);
            lz[v] += val;
            return;
        }

        Lazy(v);
        int mid = (l + r) >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = Merge(t[v << 1], t[v << 1 | 1]);
    }

    Node Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return Node();
        if (left <= l && right >= r) return t[v];

        Lazy(v);
        int mid = (l + r) >> 1;

        Node n1 = Get(v << 1, l, mid, left, right);
        Node n2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return Merge(n1, n2);
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    Node Get(int l, int r)
    {
        if (l > r) return Node();
        return Get(1, 1, n, l, r);
    }
};

int n, q;
int a[N];

SegmentTree it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    it = SegmentTree(n, a);

    while (q--)
    {
        int type, l, r, x;
        cin >> type;
        
        if (type == 1)
        {
            cin >> l >> r >> x;
            it.Update(l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << it.Get(l, r).val[1][1] << '\n';
            // Node lmao;
            // REP(haha, 67) lmao = it.Get(l, r);
            // REP(i, 2) REP(j, 2) cout << i << ' ' << j << ' ' << it.Get(l, r).val[i][j] << '\n';
            // REP(i, 2) REP(j, 2) cout << i << ' ' << j << ' ' << lmao.val[i][j] << '\n';
        }
    }

    // cout << it.t[2].mi << ' ' << it.t[2].ma << ' ' << it.t[2].val;
    // Node lmao = Merge(Node{10, 10, 0}, Node{0, 0, 0});

    // it.Get(1, 4).Print();
    // it.Merge(it.Get(1, 2), it.Get(3, 4)).Print();

    // it.t[4].Print();
    // it.t[5].Print();

    // REP(i, 2) REP(j, 2) cout << i << ' ' << j << ' ' << it.t[8].val[i][j] << '\n';
    // cout << it.t[3].x1;

    // cout << it.t[9].x1;
    cout << it.Get(1, 4).val[1][1];

    return 0;
}