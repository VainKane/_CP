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
ll const oo = 1e18;

int n, k;
int a[N];

ll dp[2][N];
ll pre[N][N], c[N][N];

bool cur = 1;

void Init()
{
    FOR(l, 1, n) FOR(r, l + 1, n) pre[l][r] = pre[l][r - 1] + (a[l] ^ a[r]);
    FOR(r, 1, n) FORD(l, r - 1, 1) c[r][l] = c[r][l + 1] + pre[l][r] - pre[l][l - 1];
}

void Solve(int l, int r, int lb, int rb)
{
    if (l > r) return;

    int mid = l + r >> 1;
    pair<ll, int> res = {oo, 0};

    FOR(i, lb, min(rb, mid - 1)) mini(res, {dp[cur ^ 1][i] + c[mid][i + 1], i});

    dp[cur][mid] = res.F;
    Solve(l, mid - 1, lb, res.S);
    Solve(mid + 1, r, res.S, rb);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k; k++;
    FOR(i, 1, n) cin >> a[i];

    Init();

    memset(dp, 0x3f, sizeof dp);
    dp[cur][0] = 0;

    REP(haha, k)
    {
        cur ^= 1;
        memset(dp[cur], 0x3f, (n + 1) * sizeof(ll));
        Solve(1, n, 0, n - 1);
    }

    cout << dp[cur][n];

    return 0;
}