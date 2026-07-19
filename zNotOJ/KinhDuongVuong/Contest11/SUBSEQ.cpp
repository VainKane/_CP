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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
int const LOG = 20;

int n;

int a[N];
int up[N][22];
int lg[N];

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
    FOR(i, 1, n) up[i][0] = a[i];
    FOR(j, 1, LOG) FOR(i, 1, n - MK(j) + 1)
        up[i][j] = GCD(up[i][j - 1], up[i + MK(j - 1)][j - 1]);
}

int GetGCD(int l, int r)
{
    if (l == r) return 0;
    int k = lg[r - l + 1];
    return GCD(up[l][k], up[r - MK(k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    FOR(i, 2, 1e6) lg[i] = lg[i / 2] + 1;

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i], a[i] = abs(a[i]);

        Build();
        int res = 0;

        int j = 1;
        FOR(i, 1, n)
        {
            while (j <= n && GetGCD(i, j) != 1)
            {
                if (i != j || a[i] != 1) maxi(res, j - i + 1);
                j++;
            }
        }

        cout << res << '\n';
    }

    return 0;
}