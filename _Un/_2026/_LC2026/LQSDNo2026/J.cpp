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
int const oo = 1e9 + 9;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx; idx ^= idx & -idx) maxi(bit[idx], val); }
    int Get(int idx)
    {
        int res = 0;
        for (; idx <= n; idx += idx & -idx) maxi(res, bit[idx]);
        return res;
    }
};

int n, q, k;

int h[N], hk[N];
ll pre[N];

int l[N];
ll f[N], g[N];

FenwickTree bit;
vector<int> vals;

void Compress()
{
    FOR(i, 1, n) vals.push_back(h[i]), vals.push_back(h[i] + k);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        hk[i] = lower_bound(all(vals), h[i] + k) - vals.begin() + 1;
        h[i] = lower_bound(all(vals), h[i]) - vals.begin() + 1;
    }

    bit = sz(vals);
}

void Init()
{
    vector<int> st;

    h[0] = oo;
    FORD(i, n, 0)
    {
        while (!st.empty() && h[i] > h[st.back()])
        {
            l[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }

    FOR(i, 1, n) f[i] = f[l[i]] + 1LL * vals[h[i] - 1] * (i - l[i]) - pre[i] + pre[l[i]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> h[i], pre[i] = pre[i - 1] + h[i];
    cin >> q >> k;

    Compress();
    Init();

    ll ma = 0;
    FOR(i, 1, n)
    {
        int j = bit.Get(hk[i]);

        g[i] = f[i] + ma;
        maxi(g[i], f[j] + 1LL * (vals[h[i] - 1] + k) * (i - j - 1) - pre[i - 1] + pre[j]);

        bit.Update(h[i], i);
        maxi(ma, g[i] - f[i]);
    }

    while (q--)
    {
        int w; cin >> w;
        cout << lower_bound(g + 1, g + n + 1, w) - g - 1 << ' ';
    }

    return 0;
}