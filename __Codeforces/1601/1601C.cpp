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

int const N = 1e6 + 5;
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

    void Update(int idx, int val) { for (; idx; idx ^= idx & -idx) bit[idx] += val; }

    int Get(int idx)
    {
        int res = 0;
        for (; idx <= n; idx += idx & -idx) res += bit[idx];
        return res;
    }
};

int n, m;

int a[N], b[N];
int pos[N];

int suf[N];

vector<int> id[N];
vector<int> c;

FenwickTree bit;

void Solve(int l, int r, int lb, int rb)
{
    if (l > r) return;
    int mid = l + r >> 1;

    suf[rb + 1] = 0;
    int pre = 0;

    FORD(i, rb, lb) suf[i] = suf[i + 1] + (a[i] < b[mid]);

    ii res = {oo, 0};
    FOR(i, lb, rb)
    {
        pre += a[i] > b[mid];
        mini(res, {pre + suf[i + 1], i});
    }

    pos[mid] = res.S;
    Solve(l, mid - 1, lb, res.S);
    Solve(mid + 1, r, res.S, rb);
}

void Compress()
{
    vector<int> vals = c;
    
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    for (auto &x : c) x = lower_bound(all(vals), x) - vals.begin() + 1;
    bit = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m) cin >> b[i];

        sort(b + 1, b + m + 1);
        Solve(1, m, 0, n);

        FOR(i, 0, n) id[i].clear();
        c.clear();

        FOR(i, 1, m) id[pos[i]].push_back(i);

        FOR(i, 0, n)
        {
            if (i) c.push_back(a[i]);
            for (auto &j : id[i]) c.push_back(b[j]); 
        }

        Compress();

        ll res = 0;
        for (auto &x : c) bit.Update(x, 1), res += bit.Get(x + 1);
        cout << res << '\n';
    }

    return 0;
}