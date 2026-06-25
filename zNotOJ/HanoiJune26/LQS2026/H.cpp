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

int const N = 1009;
int const BK = sqrt(2000) + 5;
int const OS = BK + 1;

int n, h, w;
int x[N], l[N], r[N];
bool dp[2][N][2 * BK + 5];

bool cur;
int lim;

bool Check()
{
    REP(y, h) FOR(v, -lim, lim) if (dp[cur][y][v + OS]) return true;
    return false;
}

void Update(int i, bool cur, int y, int v) { dp[cur ^ 1][y][v + OS] = y >= l[i] && y <= r[i]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> h >> w;
        
        memset(l, 0, (n + 1) * sizeof(int));
        REP(i, n) r[i] = h - 1;

        REP(i, w) cin >> x[i];
        REP(i, w)
        {
            int val; cin >> val;
            maxi(l[x[i]], val);
        }

        REP(i, w)
        {
            int val; cin >> val;
            mini(r[x[i]], val);
        }

        lim = sqrt(2 * h) + 2;
        // lim = h;
        cur = 1;

        REP(y, h) FOR(v, -lim, lim) REP(p, 2) dp[p][y][v + OS] = 0;
        dp[cur][h / 2][OS] = 1;

        REP(i, n - 1)
        {
            REP(y, h) FOR(v, -lim, lim) if (dp[cur][y][v + OS])
            {
                Update(i, cur, y + v, v);
                Update(i, cur, y + v + 1, v + 1);
                Update(i, cur, y + v - 1, v - 1);
            }
        
            cur ^= 1;
            REP(y, h) FOR(v, -lim, lim) dp[cur ^ 1][y][v + OS] = 0;
        }

        cout << (Check() ? "YES\n" : "NO\n");
    }

    return 0;
}