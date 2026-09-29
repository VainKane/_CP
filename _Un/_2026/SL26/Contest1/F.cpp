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

int const N = 509;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, k;
int a[N], b[N];
int preA[N], preB[N];

vector<int> posA[N], posB[N];

int dp[N][N];
int pre[N][N];

bool cmpA(int i, int j) { return 1LL * (preA[k] - preA[i]) * (k - j) < 1LL * (preA[k] - preA[j]) * (k - i); }
bool cmpB(int i, int j) { return 1LL * (preB[k] - preB[i]) * (k - j) < 1LL * (preB[k] - preB[j]) * (k - i); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], preA[i] = preA[i - 1] + a[i];
    FOR(i, 1, n) cin >> b[i], preB[i] = preB[i - 1] + b[i];

    FOR(j, 1, n)
    {
        k = j;
        REP(i, j) posA[j].push_back(i);
        posB[j] = posA[j];

        sort(all(posA[j]), cmpA);
        sort(all(posB[j]), cmpB);
    }

    dp[0][0] = 1;
    FOR(i, 1, n) FOR(j, 0, n)
    {
        REP(p, sz(posA[i])) pre[j][p] = (p > 0 ? pre[j][p - 1] : 0) + dp[posA[i][p]][j];
        int idx = -1;

        for (auto &q : posB[j])
        {
            while (idx + 1 < sz(posA[i]) && 1LL * (preA[i] - preA[posA[i][idx + 1]]) * (i - posA[i][idx + 1]) <= 1LL * (preB[j] - preB[q]) * (j - q)) idx++;
            // if (idx >= 0) assert(1LL * (preA[i] - preA[posA[i][idx]]) * (i - posA[i][idx]) <= 1LL * (preB[j] - preB[q]) * (j - q));
            if (idx >= 0 && 1LL * (preA[i] - preA[posA[i][idx]]) * (i - posA[i][idx]) > 1LL * (preB[j] - preB[q]) * (j - q))
            {
                // cerr << i << ' ' << j << ' ' << posA[i][idx] << ' ' << q << '\n';
            }
            if (idx >= 0) Add(dp[i][j], pre[q][idx]);
        }
    }

    cout << dp[n][n];

    // cerr << posA[2][0];
    // FOR(i, 1, n)
    // {
    //     cout << "pos " << i << ":\n";
    //     for (auto &j : pos[i]) cout << j << ' ';
    //     cout << '\n';
    // }

    return 0;
}