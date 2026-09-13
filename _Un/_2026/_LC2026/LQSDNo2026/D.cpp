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

int const N = 3e5 + 5;
ll const oo = 1e18;

int n, m, k;
vector<vector<ll>> a;

int z = 0;
ll f[N], g[N];

ll suf[N], sum[N];
vector<vector<ll>> sufMax, preMax;

bool Inc(int i)
{
    FOR(j, 1, m - 1) if (a[i][j] > a[i][j + 1]) return false;
    return true;
}

bool cmp(vector<ll> &a, vector<ll> &b) { return a[0] < b[0]; }

void Init()
{
    FOR(i, 1, n)
    {
        ll sum = 0;
        FOR(j, 1, m) sum += a[i][j];
        a[i][0] = Inc(i) * sum;
    }

    a[n + 1][0] = -1;

    sort(a.begin() + 1, a.begin() + n + 1, cmp);
    FOR(i, 1, n) if (!a[i][0] && a[i + 1][0]) z = i;
}

void CalF()
{
    vector<ll> vals;
    FOR(i, 1, z) FOR(j, 1, m) vals.push_back(a[i][j]);
    sort(all(vals), greater<ll>());

    FOR(i, 1, z * m) f[i] = f[i - 1] + vals[i - 1];
}

void InitG()
{
    FORD(i, n, z + 1) suf[i] = suf[i + 1] + a[i][0];
    preMax = sufMax = vector<vector<ll>>(n + 5, vector<ll>(m + 5, -oo));

    FOR(j, 1, m)
    {
        FOR(i, z + 1, n) preMax[i][j] = max(preMax[i - 1][j], sum[i] += a[i][j]);
        FORD(i, n, z + 1) sufMax[i][j] = max(sufMax[i + 1][j], sum[i] - a[i][0]);
    }
}

void CalG()
{
    FOR(x, 1, (n - z) * m)
    {
        int i = (x + m - 1) / m;
        int r = x - (i - 1) * m;

        maxi(g[x], suf[n - i + 2] + preMax[n - i + 1][r]);
        maxi(g[x], suf[n - i + 1] + sufMax[n - i + 1][r]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    a.assign(n + 5, vector<ll>(m + 5, 0));
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    Init();
    CalF();

    InitG();
    CalG();

    ll res = 0;
    FOR(x, 0, min(k, z * m)) maxi(res, f[x] + g[k - x]);
    cout << res;

    return 0;
}