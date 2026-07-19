#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 8009;

int n;
int a[N];
int c[N];

long long dp[2][N];
int cur = 0, pre = 1;

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> c[i];

        memset(dp, 0, sizeof dp);
        Compress();

        FOR(i, 1, n) 
        {
            swap(cur, pre);
            memset(dp[cur], 0x3f, sizeof dp[cur]);

            FOR(j, 1, n)
            {
                int cost = a[i] == j ? 0 : c[i];
                mini(dp[cur][j], dp[pre][j] + cost);
                mini(dp[cur][j], dp[cur][j - 1]);
            }
        }

        cout << *min_element(dp[cur] + 1, dp[cur] + n + 1) << '\n';
    }

    return 0;
}