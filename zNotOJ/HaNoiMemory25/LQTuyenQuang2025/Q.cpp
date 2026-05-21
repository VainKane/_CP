#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 5e5 + 5;
int const oo = 1e9;

int n, c;
int a[N], w[N];

long long dp[N];
long long pre[N];
long long maxDP[N];

vector<int> vals;

vector<int> valA[N];

void Compress(int a[])
{
    vals.clear();

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
}

void Eliminate()
{
    FOR(i, 1, n) 
    {
        if (binary_search(all(valA[w[i]]), a[i])) a[i] = 0;
        if (a[i]) valA[w[i]].push_back(a[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    FOR(i, 1, n) cin >> a[i] >> w[i];

    Compress(w);
    Compress(a);
    Eliminate();

    FOR(i, 1, n) if (a[i])
    {
        dp[i] = max(pre[a[i] - 1] - c, maxDP[w[i]]) + vals[a[i] - 1];
        maxi(pre[a[i]], max(pre[a[i] - 1], dp[i]));
        maxi(maxDP[w[i]], dp[i]);
    }

    cout << *max_element(dp + 1, dp + n + 1);
    // FOR(i, 1, n) cout << dp[i] << ' ';

    return 0;
}