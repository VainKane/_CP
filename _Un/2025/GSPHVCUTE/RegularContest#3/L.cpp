#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define name "sort"

struct FenwickTree
{
    vector<long long> bit;
    int n = 0;

    FenwickTree(int _n)
    {
        n = _n;
        bit.resize(n + 5);
    }

    void Update(int idx, int val)
    {
        if (idx == 0) return;

        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, int val)
    {
        if (l == 0 || r == 0) return;
        if (l > r) return;

        Update(l, val);
        Update(r + 1, -val);
    }

    long long Get(int idx)
    {
        long long res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    long long Get(int l, int r)
    {
        if (l == 0 || r == 0) return 0;
        if (l > r) return 0;

        return Get(r) - Get(l - 1);
    }
};

int const N = 2e5 + 5;

int n;
int a[N], c[N];
int goal[N];

long long res = 0;
int u, v;

void EasyID(int x, int y)
{
    if (x == y) u = 0, v = 0;

    u = x < y ? x : y;
    v = x > y ? x - 1 : y - 1;
}

void EasyUpdate(int i, int j, int val, FenwickTree &cntBIT, FenwickTree &sumBIT)
{
    EasyID(i, j);
    cntBIT.Update(u, v, val);
    res += val * sumBIT.Get(u, v);
}

void Init(FenwickTree &cntBIT, FenwickTree &sumBIT)
{
    vector<int> vals;
    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));

    FOR(i, 1, n) goal[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;

    FOR(i, 1, n)
    {
        EasyID(i, goal[i]);        
        cntBIT.Update(u, v, 1);
    }

    FOR(i, 1, n - 1) 
    {
        sumBIT.Update(i, c[i]);
        res += cntBIT.Get(i) * c[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) cin >> c[i];

    FenwickTree cntBIT(n);
    FenwickTree sumBIT(n - 1);

    Init(cntBIT, sumBIT);
    cout << res << '\n';

    int q; cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            EasyUpdate(x, goal[x], -1, cntBIT, sumBIT);
            EasyUpdate(y, goal[y], -1, cntBIT, sumBIT);

            swap(goal[x], goal[y]);

            EasyUpdate(x, goal[x], +1, cntBIT, sumBIT);
            EasyUpdate(y, goal[y], +1, cntBIT, sumBIT);
        }
        else
        {
            int old = sumBIT.Get(x, x);
            res += cntBIT.Get(x) * (y - old);
            sumBIT.Update(x, y - old);
        }

        cout << res << '\n';
    }

    return 0;
}