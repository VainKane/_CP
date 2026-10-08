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

int const N = 5009;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, m;

int cnt[N];
int dp[2][N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    bool cur = 1;
    for (int x = cnt[1]; x >= 0; x -= 3) dp[cur][x][0] = 1;

    FOR(i, 2, m)
    {
        cur ^= 1;
        FOR(a, 0, cnt[i]) FOR(b, 0, cnt[i - 1]) FOR(x, 0, min({cnt[i] - a, cnt[i - 1] - b, cnt[i - 2]}))
        {
            if ((cnt[i] - a - x) % 3) continue;
            Add(dp[cur][a][b], dp[cur ^ 1][b + x][x]);
        }

        FOR(a, 0, cnt[i - 1]) FOR(b, 0, cnt[i - 2]) dp[cur ^ 1][a][b] = 0;
    }

    cout << dp[cur][0][0];

    return 0;
}