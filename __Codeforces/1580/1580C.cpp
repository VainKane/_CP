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

int const N = 2e5 + 5;
int const BK = 314;

int n, q;
int x[N], y[N];

int cnt[BK + 5][BK + 5];
int d[N];

int in[N];
int cur = 0;

void UpdateLight(int x, int y, int t, int delta)
{
    FOR(i, t - y, t - 1)
    {
        int rem = i % (x + y);
        if (rem < 0) rem += x + y;
        cnt[x + y][rem] += delta;
    }
}

void UpdateHeavy(int x, int y, int t, int delta, int pos)
{
    for (int i = t + x; i <= q; i += x + y)
    {
        if (delta == -1 && i <= pos && pos < i + y && i != pos) cur--;

        d[i] += delta;
        if (i + y <= q) 
        {
            if (delta == -1 && i + y == pos) cur--;
            d[i + y] -= delta;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    FOR(i, 1, q)
    {
        int type, idx;
        cin >> type >> idx;

        int delta = type == 1 ? 1 : -1;
        int id = type == 1 ? i : in[idx];
        if (type == 1) in[idx] = i;

        if (x[idx] + y[idx] > BK) UpdateHeavy(x[idx], y[idx], id, delta, i);
        else UpdateLight(x[idx], y[idx], id, delta);

        cur += d[i];

        int res = cur;
        FOR(mod, 2, BK) res += cnt[mod][i % mod];
        cout << res << '\n';
    }

    return 0;
}