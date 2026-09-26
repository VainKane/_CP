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
#define name "breakup"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 8009;
int const MOD = 1e9 + 22071997;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int m, n, q;
bool mark[N][N];

vector<vector<ii>> dp[N][N];

bool Check(vector<ii> &a, vector<ii> &b)
{
    REP(i, sz(a) - 1) if (a[i] == b[i]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n >> q;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        int t, b, l, r;
        cin >> t >> b >> l >> r;
        FOR(x, t, b) FOR(y, l, r) mark[x][y] = true;
    }

    FOR(i, 1, m) FOR(j, 1, n)
    {
        for (auto v : dp[i][j])
        {
            v.push_back({i + 1, j});
            dp[i + 1][j].push_back(v);

            v.pop_back();
            v.push_back({i, j + 1});

            dp[i][j + 1].push_back(v);
        }
    }

    int res = 0;
    REP(p, sz(dp[m][n])) FOR(q, p + 1, sz(dp[m][n]) - 1)
        res += Check(dp[m][n][p], dp[m][n][q]);
    // cout << res;

    for (auto &x : dp[m][n][0]) cout << x.F << ' ' << x.S << '\n';

    return 0;
}