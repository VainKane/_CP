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

int const N = 1e6 + 5;

int n, t;

bitset<N> dp;
int cnt[N], last[N];

int cur = 0, pre = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    dp[0] = 1;
    int timer = 0;

    FOR(i, 1, 1e6) if (cnt[i])
    {
        memset(last, -0x3f, sizeof last);
        timer++;

        FOR(j, 0, t)
        {
            int k = j % i;
            if (dp[j]) last[k] = j;
            if ((j - last[k]) / i <= cnt[i]) dp[j] = true;
        }
    }
    
    FOR(i, 1, t) cout << dp[i];

    return 0;
}