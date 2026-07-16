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

struct FenwickTree
{
    vector<unsigned long long> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    unsigned long long Get(int idx)
    {
        unsigned long long res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    unsigned long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int const N = 1e5 + 5;
int const BK = 300;
int const GR = N / BK + 5;
int bkId[N], bkL[N], bkR[N];

int n, m, q;

int a[N];
unsigned long long pre[N], f[N];

int lb[N], rb[N];

int cnt[GR][N];
unsigned long long sum[GR];
FenwickTree bit;

void Init()
{
    FOR(i, 1, n) 
    {
        int id = bkId[i] = (i - 1) / BK + 1;
        if (!bkL[id]) bkL[id] = i;
        bkR[id] = i;
    }

    FOR(i, 1, n)
    {
        cnt[bkId[i]][lb[i]]++;
        cnt[bkId[i]][rb[i] + 1]--;
    }

    FOR(id, 1, bkId[n]) FOR(i, 1, n) cnt[id][i] += cnt[id][i - 1];

    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
    FOR(i, 1, n) f[i] = pre[rb[i]] - pre[lb[i] - 1];
    FOR(i, 1, n) sum[bkId[i]] += f[i];

    bit = FenwickTree(n);
}

void Update(int &pos, int val)
{
    bit.Update(pos, val);
    FOR(i, 1, bkId[n]) sum[i] += 1LL * val * cnt[i][pos];
}

unsigned long long Get(int l, int r)
{
    if (bkId[l] == bkId[r])
    {
        unsigned long long res = 0;
        FOR(i, l, r) res += f[i] + bit.Get(lb[i], rb[i]);
        return res;
    }

    unsigned long long res = 0;

    FOR(i, bkId[l] + 1, bkId[r] - 1) res += sum[i];
    FOR(i, l, bkR[bkId[l]]) res += f[i] + bit.Get(lb[i], rb[i]);
    FOR(i, bkL[bkId[r]], r) res += f[i] + bit.Get(lb[i], rb[i]);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> lb[i] >> rb[i];

    Init();

    int q; cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            Update(x, y - a[x]);
            a[x] = y;
        }
        else cout << Get(x, y) << '\n';
    }
}