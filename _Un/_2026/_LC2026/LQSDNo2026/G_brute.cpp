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

int const N = 2e5 + 5;
int const LOG = 20;

int n;
ii a[N];

int dp[N];
int up[N][LOG];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i].F);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i].F = lower_bound(all(vals), a[i].F) - vals.begin() + 1;
}

void Init()
{
    FOR(i, 1, n) up[i][0] = a[i].F;
    FOR(j, 1, 31 - __builtin_clz(n)) FOR(i, 1, n - MK(j) + 1)
        up[i][j] = max(up[i][j - 1], up[i + MK(j - 1)][j - 1]);
}

int Get(int l, int r)
{
    if (l > r) return 0;
    int k = 31 - __builtin_clz(r - l + 1);
    return max(up[l][k], up[r - MK(k) + 1][k]);
}

bool Check(int i, int j)
{
    int l = a[i].S, r = a[j].S;
    if (l > r) swap(l, r);
    return Get(l + 1, r - 1) < a[j].F;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F, a[i].S = i;

    Compress();
    Init();

    sort(a + 1, a + n + 1);
    FOR(i, 1, n) FOR(j, 1, i - 1) if (a[i].F > a[j].F && Check(j, i)) maxi(dp[i], dp[j] + 1);
    cout << *max_element(dp + 1, dp + n + 1) + 1;

    return 0;
}