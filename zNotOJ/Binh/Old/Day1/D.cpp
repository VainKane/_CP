#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define all(v) v.begin(), v.end()

template <class X, class Y>
    bool maxi(X &x, Y const &y)
    {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

struct SegmentTree
{
    vector<long long> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.resize(4 * n + 5);
    }

    void Update(int v, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            maxi(t[v], val);
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid) Update(2 * v, l, mid, pos, val);
        else Update(2 * v + 1, mid + 1, r, pos, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    long long GetMax(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left || l > r || left > right) return 0;
        if (left <= l && right >= r) return t[v];

        int mid = (l + r) >> 1;

        long long m1 = GetMax(2 * v, l, mid, left, right);
        long long m2 = GetMax(2 * v + 1, mid + 1, r, left, right);

        return max(m1, m2);
    }

    void Reset()
    {
        t.assign(t.size(), 0);
    }

    void Update(int pos, long long val)
    {
        if (pos > n || pos < 0) return;
        Update(1, 1, n, pos, val);
    }

    long long GetMax(int l, int r)
    {
        return GetMax(1, 1, n, l, r);
    }
};

int const N = 1e5 + 5;

int n;
int a[N], b[N];

long long f[N], g[N];

void Init()
{
    vector<int> values;
    FOR(i, 1, n) values.push_back(a[i]);

    sort(all(values));
    values.erase(unique(all(values)), values.end());

    FOR(i, 1, n) a[i] = lower_bound(all(values), a[i]) - values.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    Init();
    SegmentTree it(n);

    FORD(i, n, 1) 
    {
        f[i] = it.GetMax(a[i] + 1, n) + b[i];
        it.Update(a[i], f[i]);
    }

    it.Reset();

    FORD(i, n, 1)
    {
        g[i] = it.GetMax(1, a[i] - 1) + b[i];
        it.Update(a[i], g[i]);
    }

    long long res = 0;
    FORD(i, n, 1) 
    {
        // cout << i << ' ' << f[i] << ' ' << g[i] << '\n';
        maxi(res, f[i] + g[i] - b[i]);
    }

    cout << res;

    return 0;
}