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

int const N = 2e5 + 5;
int const LOG = 18;

int n, q;
long long a[N];
long long dp[N];

long long stMax[N][20];
long long stMin[N][20];
int lg[N];

void Build()
{
    FOR(i, 1, n) stMin[i][0] = stMax[i][0] = a[i];
    FOR(j, 1, LOG) FOR(i, 1, n - MK(j) + 1)
    {
        stMax[i][j] = max(stMax[i][j - 1], stMax[i + MK(j - 1)][j - 1]);
        stMin[i][j] = min(stMin[i][j - 1], stMin[i + MK(j - 1)][j - 1]);
    }
}

long long GetDelta(int l, int r)
{
    int k = lg[r - l + 1];
    return  max(stMax[l][k], stMax[r - MK(k) + 1][k]) - 
            min(stMin[l][k], stMin[r - MK(k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 2, n) lg[i] = lg[i / 2] + 1;

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        FOR(i, l, r) a[i] += x;
    
        Build();

        FOR(i, 1, n) 
        {
            dp[i] = 0;
            REP(j, i) maxi(dp[i], dp[j] + GetDelta(j + 1, i));
        }

        cout << dp[n] << '\n';
    }

    return 0;
}