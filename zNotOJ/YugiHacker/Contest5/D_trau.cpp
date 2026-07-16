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
#define name "farming"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const MOD = 1e9 + 7;

int m, n, k;
int pre[256][256][MK(8)];

bool Check(int mask)
{
    REP(i, n - 1) if (BIT(i, mask) && BIT(i + 1, mask)) return false;
    return true;
}

bool CheckPair(int mask1, int mask2)
{
    if (mask1 & mask2) return false;
    if (mask1 & (mask2 << 1)) return false;
    if (mask1 & (mask2 >> 1)) return false;
    return true;
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> m >> n >> k;
    if (n > m) swap(m, n);

    pre[0][0][0] = 1;
    FOR(i, 1, m) FOR(cnt, 0, min(n * i, k)) REP(mask1, MK(n)) 
    {
        int tmp = __builtin_popcount(mask1);
        if (cnt < tmp) continue;

        if (Check(mask1)) REP(mask2, MK(n)) if (CheckPair(mask1, mask2))
        {
            int dp = pre[i - 1][cnt - tmp][mask2];
            Add(pre[i][cnt][mask1], dp);
        }
    }

    int res = 0;
    REP(mask, MK(n)) Add(res, pre[m][k][mask]);
    cout << res;

    return 0;
}