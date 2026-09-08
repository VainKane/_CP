#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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
    vector<long long> bit;
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
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

struct Query
{
    int type, x, l, r;
};

int const N = 1e5 + 5;

int t;

Query qr[N];
FenwickTree bit;

vector<int> vals;

void Sub1()
{
    vector<int> v;

    FOR(i, 1, t)
    {
        if (qr[i].type == 1) v.push_back(qr[i].x);
        else if (qr[i].type == 2)
        {
            long long res = 0;
            for (auto &x : v) if (x >= qr[i].l && x <= qr[i].r) res += x;
            cout << res << '\n';
        }
        else
        {
            int l = qr[i].l - 1;
            int r = qr[i].r - 1;
            
            long long res = 0;
            sort(all(v));

            FOR(i, l, r) res += v[i];
            v.push_back(v[l] + 1);
            v.push_back(v[r] - 1);

            cout << res << '\n';
        }
    }
    
    exit(0);
}

bool CheckSub2()
{
    FOR(i, 1, t) if (qr[i].type == 3) return false;
    return true;
}

int GetId(int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, t) if (qr[i].type == 1) vals.push_back(qr[i].x);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    bit = FenwickTree(sz(vals));
}

void Sub2()
{
    Compress();
    FOR(i, 1, t)
    {
        if (qr[i].type == 1) bit.Update(GetId(qr[i].x), qr[i].x);
        else
        {
            int l = GetId(qr[i].l);
            int r = upper_bound(all(vals), qr[i].r) - vals.begin();

            cout << bit.Get(l, r) << '\n';
        }
    }

    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    FOR(i, 1, t)
    {
        cin >> qr[i].type;
        if (qr[i].type == 1) cin >> qr[i].x;
        else cin >> qr[i].l >> qr[i].r;
    }

    if (CheckSub2()) Sub2();
    else Sub1();

    return 0;
}