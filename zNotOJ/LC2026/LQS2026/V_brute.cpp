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

int const N = 5e5 + 5;
int const oo = 1e9 + 9;

int n, m, k, x;

int h[N], r[N];
int c[N], id[N];

ii a[N];
ll dp[N];

ll pre[N];

bool cmp(int i, int j) { return h[i] > h[j]; }
void Init()
{
    sort(a + 1, a + m + 1, greater<ii>());
    sort(id + 1, id + n + 1, cmp);

    int idx = 0;
    int mi = oo;

    FOR(i, 1, n)
    {
        while (idx < m && a[idx + 1].F >= h[id[i]]) mini(mi, a[++idx].S);
        c[id[i]] = mi;
        pre[i] = pre[i - 1] + r[i];
    }
}

bool Solve()
{
    memset(dp, -0x3f, sizeof dp);
    dp[0] = x;

    FOR(i, 1, n)
    {
        int cc = c[i];
        FORD(j, i - 1, max(0, i - k))
        {
            if (dp[j] >= cc) maxi(dp[i], dp[j] + pre[i] - pre[j] - cc);
            maxi(cc, c[j]);
        }

        if (dp[i] < 0 || c[i] == oo) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> x;
    FOR(i, 1, n) cin >> h[i] >> r[i], id[i] = i;
    FOR(i, 1, m) cin >> a[i].F >> a[i].S;

    Init();
    cout << (Solve() ? "Yes" : "No");

    return 0;
}