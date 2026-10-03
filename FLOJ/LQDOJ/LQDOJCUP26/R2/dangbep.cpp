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
#define name "dangbep"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 5e5 + 5;
int const M = 36;
int const MOD = 1e9 + 19972207;
int const oo = 1e9 + 9;

int PowMod(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }

    return res;
}

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

ii Merge(ii a, ii b)
{
    if (a.F != b.F) return a.F < b.F ? a : b;
    return {a.F, (a.S + b.S) % MOD};
}

struct SegmentTree
{
    vector<ii> t;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        t.assign(4 * n, {oo, 0});
    }

    void Update(int v, int l, int r, int pos, ii val)
    {
        if (l == r)
        {
            t[v] = Merge(t[v], val);
            return;
        }

        int mid = l + r >> 1;
        Update(v << 1, l, mid, pos, val);
        Update(v << 1 | 1, mid + 1, r, pos, val);

        t[v] = Merge(t[v << 1], t[v << 1 | 1]);
    }

    ii Get(int v, int l, int r, int &left, int &right)
    {
        if (l > right || r < left) return {oo, 0};
        if (left <= l && right >= r) return t[v];

        int mid = l + r >> 1;
        ii val1 = Get(v << 1, l, mid, left, right);
        ii val2 = Get(v << 1 | 1, mid + 1, r, left, right);

        return Merge(val1, val2);
    }

    void Update(int pos, ii val) { Update(1, 1, n, pos, val); }
    ii Get(int l, int r)
    {
        if (l > r) return {oo, 0};
        return Get(1, 1, n, l, r);
    }
};

int m, n, l, r;

int cnt[N][26];

int pre[N][26];
int pref[N][26];

ii dp[N][26];

int f[M], inv[M];
SegmentTree it[26];

void Init()
{
    f[0] = 1;
    FOR(i, 1, m) f[i] = 1LL * f[i - 1] * i % MOD;

    inv[m] = PowMod(f[m], MOD - 2);
    FORD(i, m - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD; 
}

int C(int k, int n)
{
    if (k > n) return 0;
    return 1LL * f[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void Update(int &i, int &c)
{
    REP(d, 26) if (c != d)
    {
        int x = dp[i][c].F - pre[i][d];
        int y = 1LL * dp[i][c].S * PowMod(pref[i][d], MOD - 2) % MOD;
        it[d].Update(i, {x, y});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n >> l >> r;
    FOR(i, 1, m)
    {
        string s; cin >> s;
        REP(j, sz(s)) cnt[j + 1][s[j] - 'a']++;
    }

    Init();

    REP(j, 26) pref[0][j] = 1;
    FOR(i, 1, n) REP(j, 26)
    {
        int need = max(0, m - 1 - cnt[i][j]);

        pre[i][j] = pre[i - 1][j] + need;
        pref[i][j] = 1LL * pref[i - 1][j] * C(need, m - cnt[i][j]);
    }

    REP(i, 26) it[i] = SegmentTree(n);

    FOR(i, 1, n) REP(j, 26) dp[i][j] = {oo, oo};
    FOR(i, l, r) REP(j, 26)
    {
        dp[i][j] = {pre[i][j], pref[i][j]};
        Update(i, j);
    }

    FOR(i, 1, n) REP(c, 26)
    {
        ii x = it[c].Get(max(i - r, 1), i - l);
        x.F += pre[i][c];
        x.S = 1LL * x.S * pref[i][c] % MOD;

        // dp[i][c] = Merge(dp[i][c], x);
        if (dp[i][c].F >= oo) continue;
        Update(i, c);

    }

    auto haha = min_element(dp[n], dp[n] + 26)->F;
    int res = 0;

    REP(j, 26) if (dp[n][j].F == haha) Add(res, dp[n][j].S);
    cout << haha << ' ' << res;

    return 0;
}