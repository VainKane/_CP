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

int const N = 5e5 + 5;

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) maxi(bit[idx], val); }

    int Get(int idx)
    {
        int res = 0;
        for (; idx; idx ^= idx & -idx) maxi(res, bit[idx]);
        return res;
    }
};

int n;

int t[N], x[N];
int id[N];

FenwickTree bit;
int a[N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(t[id[i]] - x[id[i]]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), t[id[i]] - x[id[i]]) - vals.begin() + 1;
}

bool cmp(int i, int j)
{
    if (t[i] + x[i] != t[j] + x[j]) return t[i] + x[i] < t[j] + x[j];
    return t[i] - x[i] < t[j] - x[j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> n;
    FOR(i, 1, n) cin >> t[i];
    FOR(i, 1, n) cin >> x[i];

    FOR(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, cmp);

    Compress();
    bit = FenwickTree(n);

    int res = 0;
    FORD(i, n, 1)
    {
        int dp = bit.Get(a[i] - 1) + 1;
        bit.Update(a[i], dp);
        maxi(res, dp);
    }

    cout << res;

    return 0;
}