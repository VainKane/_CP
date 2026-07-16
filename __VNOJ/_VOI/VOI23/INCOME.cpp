#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "INCOME"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;
int const LOG = 19;

int n;

int a[N], b[N];
int l[N], r[N];

int up[N][22];
int lg[N];

void Build()
{
    FOR(i, 1, n) up[i][0] = b[i];
    FOR(j, 1, LOG) FOR(i, 1, n - MK(j) + 1)
        up[i][j] = max(up[i][j - 1], up[i + MK(j - 1)][j - 1]);
}

int GetMax(int l, int r)
{
    int k = lg[r - l + 1];
    return max(up[l][k], up[r - MK(k) + 1][k]);
}

bool SwapArray()
{
    bool ok = true;
    FOR(i, 1, n) if (a[i] != b[i])
    {
        swap(a[i], b[i]);
        ok = false;
    }

    return ok;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> l[i] >> r[i];

    FOR(i, 2, n) lg[i] = lg[i / 2] + 1;

    FOR(res, 0, N)
    {
        if (SwapArray())
        {
            cout << res;
            return 0;
        }

        Build();
        FOR(i, 1, n) a[i] = max(b[i], GetMax(l[i], r[i]));
    }

    return 0;
}