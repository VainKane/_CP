#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct Stone
{
    int w, s, v;

    bool operator < (Stone const other) const
    {
        return s + w < other.s + other.w;
    }
};

int const N = 1e3 + 5;
int const M = 2e4 + 5;

int n;
Stone a[N];

long long dp[N][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int w, s, v;
        cin >> w >> s >> v;
        a[i] = {w, s, v};
    }

    sort(a + 1, a + n + 1);
    FOR(i, 1, n) FOR(j, 0, a[i].s + a[i].w)
    {
        dp[i][j] = dp[i - 1][j];
        if (j >= a[i].w) maxi(dp[i][j], dp[i - 1][j - a[i].w] + a[i].v);
    }

    cout << *max_element(dp[n], dp[n] + (int)2e4 + 1);

    return 0;
}