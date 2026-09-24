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

int const N = 3e5 + 5;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] += val; }
    
    int Get(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int n, m;

int a[N], lst[N];
int pre[N];

bool mark[N];
int cnt = 0;

FenwickTree bit;

void Init()
{
    FOR(i, 1, n)
    {
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    
        cnt += !mark[a[i]];
        mark[a[i]] = 1;
    }

    bit = FenwickTree(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    Init();
    ll res = 0;

    FOR(i, 1, n)
    {
        if (pre[i]) bit.Update(pre[i], -1);
        bit.Update(i, 1);
        res += bit.Get(pre[i] + 1, i - 1);
    }

    cout << res + 1LL * cnt * (cnt - 1) / 2 + 1LL * cnt * (m - cnt);

    return 0;
}