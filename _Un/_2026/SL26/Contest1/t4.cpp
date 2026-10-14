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

    int Get(int l, int r) { return Get(r) - Get(l - 1); }
};

int n;
int l[N], r[N], f[N];

int lf[N], rf[N];
int d[N];

int id1[N], id2[N];
int res[N];

FenwickTree bit1, bit2;

bool cmp1(int i, int j) { return f[i] > f[j]; }
bool cmp2(int i, int j) { return r[i] - l[i] > r[j] - l[j]; }

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n)
    {
        vals.push_back(l[i]);
        vals.push_back(r[i]);
        vals.push_back(f[i]);
        vals.push_back(r[i] - l[i]);
        vals.push_back(l[i] + f[i]);
        vals.push_back(r[i] - f[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    #define GetId(x) (lower_bound(all(vals), (x)) - vals.begin() + 1)

    FOR(i, 1, n)
    {
        lf[i] = GetId(l[i] + f[i]), rf[i] = GetId(r[i] - f[i]);
        f[i] = GetId(f[i]), d[i] = GetId(r[i] - l[i]);
        l[i] = GetId(l[i]), r[i] = GetId(r[i]);
    }

    bit1 = bit2 = FenwickTree(sz(vals));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> l[i] >> r[i] >> f[i];

    FOR(i, 1, n) id1[i] = id2[i] = i;
    sort(id1 + 1, id1 + n + 1, cmp1);
    sort(id2 + 1, id2 + n + 1, cmp2);

    Compress();

    int j = 1;
    FOR(i, 1, n)
    {
        for (; j <= n && d[id2[j]] >= f[id1[i]]; j++)
            bit1.Update(l[id2[j]], 1), bit2.Update(r[id2[j]], 1);

        res[id1[i]] = j - bit1.Get(rf[id1[i]] + 1, bit1.n) - bit2.Get(lf[id1[i]] - 1) - 2;
    }

    FOR(i, 1, n) cout << res[i] << ' ';

    return 0;
}