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

int const N = 4009;
int const lim = 4000;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

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

int n;
char l[N], r[N];
int dp[N][N];

int f[N], inv[N];

void Init()
{
    f[0] = 1;
    FOR(i, 1, lim) f[i] = 1LL * f[i - 1] * i % MOD;

    inv[lim] = PowMod(f[lim], MOD - 2);
    FORD(i, lim - 1, 0) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
}

int Get(char s[])
{
    int res = 0;

    dp[1][1] = 1;
    FOR(i, 2, n) FOR(j, 1, i)
    {
        if (s[i] == '<') dp[i][j] = dp[i - 1][j - 1];
        else
        {
            dp[i][j] = (dp[i - 1][i - 1] - dp[i - 1][j - 1] + MOD) % MOD;
            res = (res + 1LL * f[n] * inv[i] % MOD * dp[i - 1][j - 1]) % MOD;
        }

        Add(dp[i][j], dp[i][j - 1]);
    }

    return res;
}

bool Check(char s[])
{
    FOR(i, 2, n) if (s[i] == '<') return false;
    return true;
}

int GetNext(char s[])
{
    if (Check(s)) return f[n];
    FORD(i, n, 2) if (s[i] == '<')
    {
        s[i] = '>';
        FOR(j, i + 1, n) s[j] = '<';
        break;
    }

    return Get(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 2, n) cin >> l[i];
        FOR(i, 2, n) cin >> r[i];
        cout << (GetNext(r) - Get(l) + MOD) % MOD << '\n';
    }

    return 0;
}