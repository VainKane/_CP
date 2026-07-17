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

int const N = 260;
int const MOD = 1e9 + 7;

int m, n, k;

vector<int> v;
vector<vector<int>> valid;

vector<int> dp[2][N];
int cur = 0, pre = 1;

bool Check(int mask)
{
    REP(i, n - 1) if (BIT(i, mask) && BIT(i + 1, mask)) return false;
    return true;
}

bool CheckPair(int &mask1, int &mask2)
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
    freopen(name".out", "w", stdout);

    cin >> m >> n >> k;

    if (n > m) swap(m, n);
    
    REP(mask, MK(n)) if (Check(mask)) v.push_back(mask);
    valid.assign(sz(v), vector<int> ());

    REP(i, sz(v)) REP(j, sz(v)) if (CheckPair(v[i], v[j])) valid[i].push_back(j);
    REP(id, 2) FOR(cnt, 0, k) dp[id][cnt].assign(sz(v), 0);

    dp[cur][0][0] = 1;

    FOR(haha, 1, m)
    {
        swap(cur, pre);
        FOR(cnt, 0, k) dp[cur][cnt].assign(sz(v), 0);

        FOR(cnt, 0, k) REP(i, sz(v))
        {
            int tmp = __builtin_popcount(v[i]);
            if (cnt >= tmp) for (auto &j : valid[i])
                Add(dp[cur][cnt][i], dp[pre][cnt - tmp][j]);
        }
    }

    int res = 0;
    REP(i, sz(v)) Add(res, dp[cur][k][i]);
    cout << res;

    return 0;
}