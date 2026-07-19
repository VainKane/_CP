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

int const N = 1e5 + 5;
int const P = 109;

int n, m, p;

int d[N];
int h[N], t[N];

long long preD[N];
int a[N], id[N];

long long pre[N];
long long dp[N][P];

bool cmp(int i, int j)
{
    return a[i] < a[j];
}

void Init()
{
    FOR(i, 1, n) preD[i] = preD[i - 1] + d[i];
    FOR(i, 1, m) a[id[i] = i] = t[i] - preD[h[i]];
    sort(id + 1, id + m + 1, cmp);

    FOR(idx, 1, m)
    {
        int i = id[idx];
        pre[idx] = pre[idx - 1] + a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p;
    FOR(i, 2, n) cin >> d[i];
    FOR(i, 1, m) cin >> h[i] >> t[i];

    Init();

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    FOR(j, 1, p) FOR(i, 1, m)
    {
        int idx = id[i];
        REP(k, i) mini(dp[i][j], dp[k][j - 1] + 1LL * (i - k) * a[idx] - pre[i] + pre[k]);
    }

    cout << dp[m][p];

    return 0;
}