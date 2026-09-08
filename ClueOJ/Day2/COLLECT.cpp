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
#define name "COLLECT"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
long long const oo = 1e18;

int n;

int g[N];

long long pre[N];
long long preD[N];

long long dp[N], f[N];
int lb[N];

long long GetSum(int l, int r)
{
    if (l > r) return 0;
    return preD[r] - preD[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    FOR(i, 1, n - 1)
    {
        int x; cin >> x;
        preD[i] = preD[i - 1] + x;
    }

    FOR(i, 1, n) cin >> g[i];

    int q; cin >> q;
    while (q--)
    {
        int w; cin >> w;

        int j = 1;
        FOR(i, 1, n)
        {
            lb[i] = 0;
            while (pre[i] - pre[j - 1] > w && j < i) j++;
            if (pre[i] - pre[j - 1] <= w) lb[i] = j - 1;
        }

        memset(f, 0x3f, sizeof f);
        f[0] = g[1];

        deque<long long> dq;

        FOR(i, 1, n)
        {
            while (!dq.empty() && dq.front() < lb[i]) dq.pop_front();
            while (!dq.empty() && f[dq.back()] >= f[i - 1]) dq.pop_back();
            dq.push_back(i - 1);

            if (!dq.empty()) dp[i] = f[dq.front()] + preD[i - 1] + g[i];
            f[i] = dp[i] - preD[i] + g[i + 1];
        }

        cout << dp[n] << '\n';
    }

    return 0;
}
