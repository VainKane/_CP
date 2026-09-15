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
int const LOG = 20;
int const oo = 1e9 + 9;

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

        int mid = l + r >> 1;
        if (pos <= mid) Update(v << 1, l, mid, pos, val);
        else Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    int Get(int v, int l, int r, int left, int right)
    {
        if (l > right || r < left) return 0;
        if (left <= l && right >= r) return t[v];

        int mid = l + r >> 1;
        int val1 = Get(v << 1, l, mid, left, right);
        int val2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return max(val1, val2);
    }

    void Update(int pos, int val) { return Update(1, 1, n, pos, val); }
    int Get(int l, int r) { return Get(1, 1, n, l, r); }
};

int n;
ii a[N];

int dp[N];
SegmentTree it;

int l[N], r[N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i].F);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i].F = lower_bound(all(vals), a[i].F) - vals.begin() + 1;
}

void Init()
{
    vector<int> st;
    a[0].F = a[n + 1].F = oo;

    FOR(i, 1, n + 1)
    {
        while (!st.empty() && a[i].F >= a[st.back()].F)
        {
            r[st.back()] = i - 1;
            st.pop_back();
        }
        st.push_back(i);
    }

    FORD(i, n, 0)
    {
        while (!st.empty() && a[i].F >= a[st.back()].F)
        {
            l[st.back()] = i + 1;
            st.pop_back();
        }
        st.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F, a[i].S = i;

    Compress();
    Init();
    sort(a + 1, a + n + 1);

    it = SegmentTree(n);

    FOR(i, 1, n)
    {
        dp[i] = it.Get(l[a[i].S], r[a[i].S]) + 1;
        it.Update(a[i].S, dp[i]);
    }

    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}