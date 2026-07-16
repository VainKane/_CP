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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const LOG = 17;

int n;
int a[N];

int up[N][20];
int upMin[N][20];

int lg[N];

vector<int> pos[N];
vector<int> vals = {1};

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

void Build()
{
    FOR(i, 1, n) upMin[i][0] = up[i][0] = vals[a[i] - 1];
    FOR(j, 1, LOG) FOR(i, 1, n - MK(j) + 1)
    {
        up[i][j] = GCD(up[i][j - 1], up[i + MK(j - 1)][j - 1]);
        upMin[i][j] = min(upMin[i][j - 1], upMin[i + MK(j - 1)][j - 1]);
    }

    FOR(i, 2, n) lg[i] = lg[i >> 1] + 1;
}

int GetGCD(int l, int r)
{
    int k = lg[r - l + 1];
    return GCD(up[l][k], up[r - MK(k) + 1][k]);
}

int GetMin(int l, int r)
{
    int k = lg[r - l + 1];
    return min(upMin[l][k], upMin[r - MK(k) + 1][k]);
}

int GetId(int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = GetId(a[i]);
}

int Count(int x, int idx)
{
    if (pos[x].empty()) return 0;
    return upper_bound(all(pos[x]), idx) - pos[x].begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Compress();
    Build();

    FOR(i, 1, n) pos[a[i]].push_back(i);

    int t; cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int x = GetId(GetGCD(l, r));

        int res = Count(x, r) - Count(x, l - 1);
        if (GetMin(l, r) > GetGCD(l, r)) res = 0;
        cout << r - l + 1 - res << '\n';
    }

    return 0;
}