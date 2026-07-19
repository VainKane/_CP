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
int cnt[2 * N * N];
int s = 0;

void Insert(int x)
{
    s += x;
    FORD(j, s, x) Add(dp[j], dp[j - x]);
}

void Remove(int x)
{
    FOR(j, x, s) Sub(dp[j], dp[j - x]);
    s -= x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    dp[0] = 1;
    FOR(i, 1, n) Insert(a[i]);
    if ((s & 1) || !dp[s / 2])
    {
        cout << 0;
        return 0;
    }

    FOR(i, 1, n)
    {
        Remove(a[i]);
        FOR(j, 0, s) if (dp[j] && 2 * j > s) cnt[2 * j - s]++;
        Insert(a[i]);
    }

    vector<int> res;
    FOR(i, 1, s) if (cnt[i] == n) res.push_back(i);

    cout << sz(res) << '\n';
    for (auto &x : res) cout << x << ' ';

    return 0;
}