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
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define TASKNAME "TASKNAMEGOESHERE"

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

template<typename T> bool mini(T &a, const T &b) {
     return a > b ? a = b, 1 : 0;
}

template<typename T> bool maxi(T &a, const T &b) {
     return a < b ? a = b, 1 : 0;
}

const int maxn = 1e6 + 5;
bool sieve[maxn];
void gen() {
    memset(sieve, 1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < maxn; ++i) if (sieve[i]) for (int j = i * i; j < maxn; j += i) sieve[j] = 0;
}

int m, n;
vi2d a, pre;

namespace sub2 {
    const int maxn = 55;
    bool check() { return max(m, n) < maxn; }
    int pref[maxn][maxn];
    void solve() {
        memset(pref, 0, sizeof pref);
        FOR(i, 1, m) FOR(j, 1, n) pref[i][j] = not sieve[a[i][j]] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        auto get = [](int r1, int c1, int r2, int c2) {
            return pref[r2][c2] - pref[r2][c1 - 1] - pref[r1][c2 - 1] + pref[r1 - 1][c1 - 1];
        };

        int ans = 0;
        FOR(r1, 1, m) FOR(c1, 1, n) for (int r2 = r1, c2 = c1; r2 <= m and c2 <= n; ++r2, ++c2) if (get(r1, c1, r2, c2) <= 1) {
            ans = max(ans, (r2 - r1 + 1) * (c2 - c1 + 1));
        }
        cout << ans << endl;
    }
}

int Get(int x, int y, int u, int v)
{
    return pre[u][v] - pre[u][y - 1] - pre[x - 1][v] + pre[x - 1][y - 1];
}

bool Check(int k)
{
    FOR(i, 1, m - k + 1) FOR(j, 1, n - k + 1) if (Get(i, j, i + k - 1, j + k - 1) <= 1) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gen();
    cin >> m >> n;
//    a.resize(m + 1, vi(n + 1));
    pre.assign(m + 1, vi(n + 1, 0));
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j)
    {
        int x; cin >> x;
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + !sieve[x];
    }

    int l = 1;
    int r = min(m, n);
    int res = l;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res * res;
//    if (sub2::check()) return sub2::solve(), 0;


    return 0;
}
