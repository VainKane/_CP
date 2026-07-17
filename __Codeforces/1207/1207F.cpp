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

int const N = 5e5 + 5;
int const BK = 700;

int a[N];
int sum[BK + 5][BK + 5];

void Update(int pos, int val)
{
    a[pos] += val;
    FOR(mod, 1, BK) sum[mod][pos % mod] += val;
}

int Get(int mod, int rem)
{
    if (mod > BK)
    {
        int res = 0;
        for (int i = rem; i <= 5e5; i += mod) res += a[i];
        return res;
    }

    return sum[mod][rem];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) Update(x, y);
        else cout << Get(x, y) << '\n';
    }

    return 0;
}