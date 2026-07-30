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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
int const M = MK(10) + 5;

int n, k;
int a[N][11];

ll val[M], pre[M];
ll dp[N];

void Try(int &id, int mask, int pos, ll sum)
{
    if (pos == k)
    {
        val[mask] = sum;
        return;
    }

    Try(id, mask, pos + 1, sum + a[id][pos]);
    Try(id, mask | MK(pos), pos + 1, sum - a[id][pos]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) REP(j, k) cin >> a[i][j];

    memset(pre, -0x3f, sizeof pre);
    FOR(i, 1, n)
    {
        Try(i, 0, 0, 0);
        REP(mask, MK(k))
        {
            maxi(pre[mask], dp[i - 1] - val[mask]);
            maxi(dp[i], pre[mask] + val[mask]);
        }
    }

    cout << dp[n];

    return 0;
}