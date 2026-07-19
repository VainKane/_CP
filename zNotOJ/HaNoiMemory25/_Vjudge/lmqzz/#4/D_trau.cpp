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

int const N = 509;
int const MOD = 1e9 + 2277;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int const &y)
{
    x -= y;
    if (x < 0) x += MOD;
}

int n;
int a[N];

int dp[2 * N * N];
int s = 0;

bool Check()
{
    FOR(i, 1, n)
    {
        int j = s - a[i];
        if (j & 1) return false;

        bool ok = true;
        FOR(j, a[i], s) Sub(dp[j], dp[j - a[i]]);
        if (!dp[j / 2]) ok = false;
        FORD(j, s, a[i]) Add(dp[j], dp[j - a[i]]);

        if (!ok) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], s += a[i];

    vector<int> res;

    dp[0] = 1;
    FOR(i, 1, n) FORD(j, s, a[i]) Add(dp[j], dp[j - a[i]]);
    if ((s & 1) || !dp[s / 2])
    {
        cout << 0;
        return 0;
    }

    FOR(x, 1, s)
    {
        s += x;
        FORD(j, s, x) Add(dp[j], dp[j - x]);
        if (Check()) res.push_back(x);
        FOR(j, x, s) Sub(dp[j], dp[j - x]);
        s -= x;
    }

    cout << sz(res) << '\n';
    for (auto &x : res) cout << x << ' ';

    return 0;
}