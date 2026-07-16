#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1ll << (i))
#define BIT(i, x) (((x) >> (i)) & 1)
#define name "diduduadi"

int const MOD = 998244353;

long long n;
int k;

int dp[65][MK(9) + 5][15];
int newCmp[MK(9) + 5][MK(10) + 5];
vector<int> masks[2];

bool Get(bool b1, bool b2, bool cmp)
{
    if (b1 != b2) return b1 < b2;
    return cmp;
}

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Init()
{
    REP(cmp, MK(k - 1)) REP(mask, MK(k))
    {
        REP(j, k - 1) if (Get(BIT(j, mask), BIT(j + 1, mask), BIT(j, cmp))) 
            newCmp[cmp][mask] |= MK(j);
    }

    REP(mask, MK(k))
    {
        int type = __builtin_popcount(mask) & 1;
        masks[type].push_back(mask);
    }

    dp[0][0][0] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;

    n -= k;
    if (n < k - 1)
    {
        cout << 0;
        return 0;
    }

    int lg = __lg(n) + 1;
    Init();

    REP(i, lg) REP(cmp, MK(k - 1)) REP(carry, k) if (dp[i][cmp][carry])
    {
        int type = BIT(i, n) ^ (carry & 1);
        for (auto mask : masks[type])
        {
            int tmp = carry + __builtin_popcount(mask);
            Add(dp[i + 1][newCmp[cmp][mask]][tmp >> 1], dp[i][cmp][carry]);
        }
    }

    cout << dp[lg][MK(k - 1) - 1][0];

    return 0;
}