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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const LOG = 19;

struct SegmentTree
{
    vector<int> t, lz;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
    }

    void Lazy(int v)
    {
        if (lz[v])
        {
            FOR(u, v << 1, v << 1 | 1) t[u] += lz[v], lz[u] += lz[v];
            lz[v] = 0;
        }
    }

    void Update(int v, int l, int r, int left, int right, int val)
    {
        if (l > right || r < left) return;
        if (left <= l && right >= r)
        {
            t[v] += val;
            lz[v] += val;
            return;
        }
    
        Lazy(v);
        int mid = l + r >> 1;

        Update(v << 1, l, mid, left, right, val);
        Update(v << 1 | 1, mid + 1, r, left, right, val);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    void Update(int l, int r, int val)
    {
        if (l > r || l < 1 || r > n) return;
        Update(1, 1, n, l, r, val);
    }
};

int n;
int l[N], r[N];

SegmentTree it;
int nxt[N][LOG];

void Compress()
{
    vector<int> vals;
    FOR(i, 1, n)
    {
        vals.push_back(l[i]);
        vals.push_back(r[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        l[i] = lower_bound(all(vals), l[i]) - vals.begin() + 1;
        r[i] = lower_bound(all(vals), r[i]) - vals.begin() + 1;
    }

    it = SegmentTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> l[i] >> r[i];

    Compress();

    int j = 1;
    it.Update(l[1], r[1], 1);

    memset(nxt, 0x3f, sizeof nxt);

    FOR(i, 1, n)
    {
        while (it.t[1] <= 1 && j <= n) j++, it.Update(l[j], r[j], 1);
        it.Update(l[i], r[i], -1);
        nxt[i][0] = j;
    }

    FOR(j, 1, 31 - __builtin_clz(n)) FOR(i, 1, n) if (nxt[i][j - 1] <= n)
        nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];

    int q; cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int pos = l, res = 0;
        FORD(i, 31 - __builtin_clz(n), 0) if (nxt[pos][i] <= r)
            pos = nxt[pos][i], res += MK(i);
        
        cout << res + 1 << '\n';
    }

    return 0;
}