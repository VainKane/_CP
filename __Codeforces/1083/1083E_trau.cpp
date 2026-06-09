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

int const N = 1e6 + 5;

int n;

int x[N], y[N];
long long a[N];

int id[N];

long long dp[N];

bool cmp(int i, int j)
{
    return x[i] < x[j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i] >> a[id[i] = i];

    sort(id + 1, id + n + 1, cmp);

    FOR(i, 1, n) REP(j, i) maxi(dp[i], dp[j] + 1LL * (x[id[i]] - x[id[j]]) * y[id[i]] - a[id[i]]);
    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}