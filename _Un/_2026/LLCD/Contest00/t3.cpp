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

int const N = 4009;

int n;
int a[N];

vector<int> vals ;
int last[N];

int dp[N][N];

#define GetId(x) (lower_bound(all(vals), (x)) - vals.begin() + 1) 

void Compress()
{
    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Compress();
    int res = 1 + (n > 1);

    FOR(i, 1, n)
    {
        FOR(j, i + 1, n)
        {
            dp[i][j] = 2;
            int id = GetId(2 * a[i] - a[j]);
            if (id > sz(vals) || id == 0 || vals[id - 1] != 2 * a[i] - a[j]) continue;

            maxi(dp[i][j], dp[last[id]][i] + 1);
            maxi(res, dp[i][j]);
        }

        last[GetId(a[i])] = i;
    }

    cout << res;

    return 0;
}
