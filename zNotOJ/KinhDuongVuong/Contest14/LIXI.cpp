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
    vector<long long> t;
    vector<long long> lz;
    vector<int> len;
    int n;

    void Build(int v, int l, int r, vector<long long> &a)
    {
        if (l == r)
        {
            t[v] = a[l];
            len[v] = 1;
            return;
        }

        int mid = (l + r) >> 1;
        Build(2 * v, l, mid, a);
        Build(2 * v + 1, mid + 1, r, a);

        t[v] = t[2 * v] + t[2 * v + 1];
        len[v] = r - l + 1;
    }

    SegmentTree(vector<long long> a)
    {
        n = sz(a) - 1;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        len.assign(4 * n + 5, 0);

        if (n) Build(1, 1, n, a);
    }

    void Push(int v)
    {
        if (lz[v])
        {
            FOR(u, 2 * v, 2 * v + 1)
            {
                t[u] += len[u] * lz[v];
                lz[u] += lz[v];
            }
            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, long long val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] += len[v] * val;
            lz[v] += val;
            return;
        }

        Push(v);
        int mid = (l + r) >> 1;

        Update(2 * v, l, mid, left, right, val);
        Update(2 * v + 1, mid + 1, r, left, right, val);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    long long Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        Push(v);
        int mid = (l + r) >> 1;

        long long val1 = Get(2 * v, l, mid, left, right);
        long long val2 = Get(2 * v + 1, mid + 1, r, left, right);

        return val1 + val2;
    }

    void Update(int l, int r, long long val)
    {
        if (l > r) return;
        Update(1, 1, n, l, r, val);
    }

    long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(1, 1, n, l, r);
    }
};

int const N = 1e5 + 5;

int n, k;
int a[N];

SegmentTree it(vector<long long> {0});

void Init()
{
    vector<long long> pre;
    pre.assign(n + 1, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
    it = SegmentTree(pre);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    Init();

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            pair<int, long long> b[k + 2];
            FOR(i, 1, k)
            {
                cin >> b[i].F;
                b[i].S = a[b[i].F];
            }

            b[k + 1] = b[1];
        
            FOR(i, 1, k)
            {
                int id = b[i].F;
                it.Update(id, n, b[i + 1].S - a[id]);
                a[id] = b[i + 1].S;
            }
        }
        else
        {
            int l, r, m;
            cin >> l >> r >> m;
            cout << it.Get(l + m - 1, r) - it.Get(l - 1, r - m) << '\n';
        }
    }

    return 0;
}