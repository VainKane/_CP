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
int const K = 12;

ll Ceil(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    ll x, a, b;

    ll operator ()() { return x * a + b; }
    ll operator ()(int x) { return x * a + b; }
};

struct ConvexHullTrick
{
    vector<Segment> seg;
    int id = 0;

    void Add(ll a, ll b)
    {
        while (!seg.empty() && seg.back()() >= seg.back().x * a + b) seg.pop_back();
        if (seg.empty()) seg.push_back({-N, a, b});
        else if (seg.back().a != a)
        {
            ll x = Ceil(b - seg.back().b, seg.back().a - a);
            maxi(x, -1LL * N); mini(x, 36LL);
            seg.push_back({x, a, b});
        }
    }

    ll Get(int x)
    {
        for (mini(id, sz(seg) - 1); id < sz(seg) && seg[id].x <= x; id++); id--;
        return seg[id](x);
    }    

    void Reset() { seg.clear(); id = 0; }
};

int n, k;
int a[N];

int pre[N];
ll preI[N];

ConvexHullTrick cht;
ll dp[N][K];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FORD(i, n, 1) cin >> a[i];

    FOR(i, 1, n)
    {
        pre[i] = pre[i - 1] + a[i];
        preI[i] = preI[i - 1] + 1LL * (n - i) * a[i];
    }

    memset(dp, -1, sizeof dp);
    FOR(j, 1, k)
    {
        cht.Reset();
        cht.Add(0, 0);

        FOR(i, 1, n)
        {
            dp[i][j] = cht.Get(i - n) + preI[i] - 1LL * (n - i) * pre[i];
            if (dp[i][j - 1] != -1) cht.Add(-pre[i], -preI[i] + dp[i][j - 1]);
        }
    }

    cout << dp[n][k];

    return 0;
}