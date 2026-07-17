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

    void Build(int v, int l, int r)
    {
        if (l == r)
        {
            t[v] = 1;
            return;
        }

        int mid = (l + r) >> 1;
        Build(2 * v, l, mid);
        Build(2 * v + 1, mid + 1, r);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, 0);
        if (n) Build(1, 1, n);
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

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int Get(int v, int l, int r, int k)
    {
        if (l == r) return l;

        int mid = (l + r) >> 1;
        if (t[2 * v] >= k) return Get(2 * v, l, mid, k);
        else return Get(2 * v + 1, mid + 1, r, k - t[2 * v]);
    }

    void Update(int pos, int val)
    {
        Update(1, 1, n, pos, val);
    }

    int Get(int k)
    {
        return Get(1, 1, n, k);
    }
};

int n;
long long k;

SegmentTree it;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
 
    it = SegmentTree(n);
    FOR(i, 1, n)
    {
        long long cnt = 1LL * (n - i) * (n - i - 1) / 2;
        if (cnt >= k)
        {
            int x = it.Get(1);
            it.Update(x, 0);
            cout << x << ' ';
        }
        else
        {
            int x = it.Get(k - cnt + 1);
            it.Update(x, 0);
            k -= k - cnt;
            cout << x << ' ';
        }
    }

    return 0;
}
