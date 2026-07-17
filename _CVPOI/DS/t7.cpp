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
    vector<int> bit;
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

    int Get(int idx)
    {
        int res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }
};

int const N = 2e5 + 5;

int h, w, n;
int r[N], c[N];

FenwickTree bit;
vector<int> ed[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> h >> w >> n;

    FOR(i, 1, h) r[i] = w + 1;
    FOR(i, 1, w) c[i] = h + 1;

    FOR(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        mini(r[x], y);
        mini(c[y], x);
    }

    bit = FenwickTree(w);
    long long res = 0;

    FOR(i, 1, r[1] - 1)
    {
        res += c[i] - 1;

        ed[c[i]].push_back(i);
        bit.Update(i, 1);
    }

    FOR(i, 1, c[1] - 1)
    {
        res += r[i] - 1;
        
        res -= bit.Get(r[i] - 1);
        for (auto &j : ed[i]) bit.Update(j, -1);
    }

    cout << res;

    return 0;
}